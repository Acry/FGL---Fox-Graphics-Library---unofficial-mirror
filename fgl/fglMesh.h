#ifndef _FGLMESH_H_
#define _FGLMESH_H_

#include "fglSceneGraph.h"
#include "fglVBO.h"
#include "fglSkel.h"
#include "fglAnim.h"
#include "fglMem.h"

#define fglMESH_STATIC 1
#define fglMESH_DYNAMIC 2

class fglMesh : public fglVisual
{
private:
	unsigned _nFaces;
	unsigned _nIndsPerFace;
	unsigned _nFaceMode;
	unsigned _nUsage;

public:

	unsigned nFaces(void) const { return _nFaces; }
	unsigned nIndsPerFace(void) const { return _nIndsPerFace; }
	unsigned nFaceMode(void) const { return _nFaceMode; }
	unsigned nUsage(void) const { return _nUsage; }

	fglREF<fglVBO_Array> oVBO;
	fglREF<fglVBO_Array> oVBOBones;
	fglREF<fglVBO_Element_Array> oVBOInds;

	fglREF<fglVERTEX> aVerts;
	fglREF<fglVERTEXBONES> aVertBones;

	fglREF<fglINDEX> aInds;
	
	fglREF<fglBone> aBones;
	
	fglMesh(void);
	virtual ~fglMesh(void);
	virtual fglString fgl_class(void) const { return "mesh"; }

	void setFaces(int pnFaces, int pnIndsPerFace);
	fglFACE aFaces(int i) const;

	virtual bool copy(const fglBind* poSrc, fglBITFLAG pnShare=0);

	void buildVBO(unsigned pnUsage=fglMESH_STATIC);
	void fillVBO(void);
	virtual void calcBounds(void);
	
	static void renderMesh(const fglMesh* poMesh);
	
	void renderNormals(void) const;
	
	void transformByBones(void);

	virtual bool testIntersection(fglRAY& poRay, int* pnFaceId=NULL, int* pnVertId=NULL, fglVECTOR* poPointIn=NULL) const;

	virtual void call(fglEvent& poEvent);
};

#endif