#include "sbwCook.h"


SBWCook::SBWCook()
{
	this->convexHullShape = new btConvexHullShape();

}


btConvexHullShape* SBWCook::getConvexHullShape(Ogre::Mesh *mesh , Ogre::Vector3 scale , Ogre::Vector3 position,Ogre::Quaternion orient)
{
	bool added_shared = false;
	size_t current_offset = 0;
	size_t shared_offset = 0;
	size_t next_offset = 0;
	size_t index_offset = 0;

	size_t vertex_count = 0;
	

	for(unsigned short i = 0; i < mesh->getNumSubMeshes(); ++i)
	{
		Ogre::SubMesh* submesh = mesh->getSubMesh(i);

		if(submesh->useSharedVertices)
		{

			if(!added_shared)
			{
				vertex_count += mesh->sharedVertexData->vertexCount;
				added_shared = true;
			}



		}else
		{
			vertex_count += submesh->vertexData->vertexCount;
		}


	}

	added_shared = false;


	for(unsigned int i = 0; i < mesh->getNumSubMeshes() ; ++i)
	{
		Ogre::SubMesh* submesh = mesh->getSubMesh(i);

		Ogre::VertexData* vertex_data = submesh->useSharedVertices ? mesh->sharedVertexData : submesh->vertexData;

		if ((!submesh->useSharedVertices) || (submesh->useSharedVertices && !added_shared))
		{
			if(submesh->useSharedVertices)
			{
				added_shared = true;
				shared_offset = current_offset;
			}

			const Ogre::VertexElement* posElem =
				vertex_data->vertexDeclaration->findElementBySemantic(Ogre::VES_POSITION);

			Ogre::HardwareVertexBufferSharedPtr vbuf =
				vertex_data->vertexBufferBinding->getBuffer(posElem->getSource());

			unsigned char* vertex =
				static_cast<unsigned char*>(vbuf->lock(Ogre::HardwareBuffer::HBL_READ_ONLY));

			float* pReal;

			for( size_t j = 0; j < vertex_data->vertexCount; ++j, vertex += vbuf->getVertexSize())
            {
                posElem->baseVertexPointerToElement(vertex, &pReal);
                Ogre::Vector3 pt(pReal[0], pReal[1], pReal[2]);
                pt = (orient * (pt * scale));
				this->convexHullShape->addPoint(SBWConvert::toBullet(pt));
            }
 
            vbuf->unlock();
            next_offset += vertex_data->vertexCount;

		}


	}

	btShapeHull* hull = new btShapeHull(convexHullShape);
	btScalar margin = convexHullShape->getMargin();
	hull->buildHull(margin);
	btConvexHullShape* simplifiedConvexShape = new btConvexHullShape();
	const btVector3 *vertexP = hull->getVertexPointer();

	std::cout << convexHullShape->getNumVertices() << std::endl;
	std::cout << "SIMP:" << hull->numVertices() << std::endl;

	for(int i = 0;i < hull->numVertices();++i)
	{
		simplifiedConvexShape->addPoint(vertexP[i]);
	}

	delete this->convexHullShape;
	
	this->convexHullShape = simplifiedConvexShape;

	return this->convexHullShape;

}