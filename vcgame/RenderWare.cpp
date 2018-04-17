/* source: https://github.com/DK22Pac/plugin-sdk */

#include "vc_game.h"

RsGlobalType* RsGlobal = 0;

/* rwplcore.h */

RwStream* 	(*RwStreamOpen)(RwStreamType type, RwStreamAccessType accessType, const void* pData);
RwBool 		(*RwStreamClose)(RwStream* stream, void* pData);
RwUInt32 	(*RwStreamRead)(RwStream* stream, void* buffer, RwUInt32 length);
RwStream* 	(*RwStreamWrite)(RwStream* stream, const void* buffer, RwUInt32 length);
RwStream* 	(*RwStreamSkip)(RwStream* stream, RwUInt32 offset);
RwBool 		(*RwMatrixDestroy)(RwMatrix* mpMat);
RwMatrix* 	(*RwMatrixCreate)(void);
RwMatrix* 	(*RwMatrixMultiply)(RwMatrix* matrixOut, const RwMatrix* MatrixIn1, const RwMatrix* matrixIn2); 
RwMatrix* 	(*RwMatrixTransform)(RwMatrix* matrix, const RwMatrix* transform, RwOpCombineType combineOp); 
RwMatrix* 	(*RwMatrixOrthoNormalize)(RwMatrix* matrixOut, const RwMatrix* matrixIn); // 
RwMatrix* 	(*RwMatrixInvert)(RwMatrix* matrixOut, const RwMatrix* matrixIn); // 
RwMatrix* 	(*RwMatrixScale)(RwMatrix* matrix, const RwV3d* scale, RwOpCombineType combineOp); // 
RwMatrix* 	(*RwMatrixTranslate)(RwMatrix* matrix, const RwV3d* translation, RwOpCombineType combineOp); // 
RwMatrix* 	(*RwMatrixRotate)(RwMatrix* matrix, const RwV3d* axis, RwReal angle, RwOpCombineType combineOp); // 
RwMatrix* 	(*RwMatrixRotateOneMinusCosineSine)(RwMatrix* matrix, const RwV3d* unitAxis, RwReal oneMinusCosine, RwReal sine, RwOpCombineType combineOp); // 
RwMatrix* 	(*RwMatrixUpdate)(RwMatrix* matrix); // 
RwMatrix* 	(*RwMatrixOptimize)(RwMatrix* matrix, const RwMatrixTolerance* tolerance); // 
RwReal 		(*_rwMatrixDeterminant)(const RwMatrix* matrix); // 
RwReal 		(*_rwMatrixNormalError)(const RwMatrix* matrix); // 
RwReal 		(*_rwMatrixOrthogonalError)(const RwMatrix* matrix); // 
RwReal 		(*_rwMatrixIdentityError)(const RwMatrix* matrix); // 
RwReal 		(*RwV3dNormalize)(RwV3d* out, const RwV3d* in); // 
RwReal 		(*RwV3dLength)(const RwV3d* in); // 
RwV3d* 		(*RwV3dTransformPoints)(RwV3d* pointsOut, const RwV3d* pointsIn, RwInt32 numPoints, const RwMatrix* matrix); // 
RwV3d* 		(*RwV3dTransformVectors)(RwV3d* vectorsOut, const RwV3d* vectorsIn, RwInt32 numPoints, const RwMatrix* matrix); // 
RwReal 		(*_rwSqrt)(const RwReal num); // 
RwReal 		(*_rwInvSqrt)(const RwReal num); // 
RwReal 		(*RwIm2DGetNearScreenZ)(void); // 
RwReal 		(*RwIm2DGetFarScreenZ)(void); // 
RwBool 		(*RwRenderStateGet)(RwRenderState state, void* value); // 
RwBool 		(*RwRenderStateSet)(RwRenderState state, void* value); // 
RwBool 		(*RwIm2DRenderLine)(RwIm2DVertex* vertices, RwInt32 numVertices, RwInt32 vert1, RwInt32 vert2); // 
RwBool 		(*RwIm2DRenderPrimitive)(RwPrimitiveType primType, RwIm2DVertex* vertices, RwInt32 numVertices); // 
RwBool 		(*RwIm2DRenderIndexedPrimitive)(RwPrimitiveType primType, RwIm2DVertex* vertices, RwInt32 numVertices, RwImVertexIndex* indices, RwInt32 numIndices); // 
RwFileFunctions* (*RwOsGetFileInterface)(void); // 
RwError* 	(*RwErrorGet)(RwError* code); // 
RwError* 	(*RwErrorSet)(RwError* code); // 
RwInt32 	(*_rwerror)(RwInt32 code, ...); // 
RwBool 		(*RwResourcesEmptyArena)(void); // 
RwResEntry* (*RwResourcesAllocateResEntry)(void* owner, RwResEntry* ownerRef, RwInt32 size, RwResEntryDestroyNotify destroyNotify); // 
RwBool 		(*RwResourcesFreeResEntry)(RwResEntry* entry); // 
void 		(*_rwResourcesPurge)(void); // 
RwBool 		(*RwStreamFindChunk)(RwStream* stream, RwUInt32 type, RwUInt32* lengthOut, RwUInt32* versionOut); // 
RwStream* 	(*_rwStreamWriteVersionedChunkHeader)(RwStream* stream, RwInt32 type, RwInt32 size, RwUInt32 version, RwUInt32 buildNum); // 
RwStream* 	(*RwStreamWriteReal)(RwStream* stream, const RwReal* reals, RwUInt32 numBytes); // 
RwStream* 	(*RwStreamWriteInt32)(RwStream* stream, const RwInt32* ints, RwUInt32 numBytes); // 
RwStream* 	(*RwStreamReadReal)(RwStream* stream, RwReal* reals, RwUInt32 numBytes); // 
RwStream* 	(*RwStreamReadInt32)(RwStream* stream, RwInt32* ints, RwUInt32 numBytes); // 

/* rwcore.h */

RxHeap* 	(*RxHeapCreate)(RwUInt32 size); // 
void 		(*RxHeapDestroy)(RxHeap* heap); // 
RwBool 		(*_rxHeapReset)(RxHeap* heap); // 
void* 		(*RxHeapAlloc)(RxHeap* heap, RwUInt32 size); // 
void 		(*RxHeapFree)(RxHeap* heap, void* block); // 
RwBool 		(*_rxPipelineOpen)(void); // 
RwBool 		(*_rxPipelineClose)(void); // 
RxPipeline* (*RxPipelineCreate)(void); // 
void 		(*_rxPipelineDestroy)(RxPipeline* Pipeline); // 
RxHeap* 	(*RxHeapGetGlobalHeap)(void); // 
RxPipeline* (*RxPipelineExecute)(RxPipeline* pipeline, void* data, RwBool heapReset); // 
void 		(*_rxPacketDestroy)(RxPacket* Packet); // 
RxPipelineNode* (*RxPipelineFindNodeByName)(RxPipeline* pipeline, const RwChar* name, RxPipelineNode* start, RwInt32* nodeIndex); // 
RxLockedPipe* (*RxPipelineLock)(RxPipeline* pipeline); // 
RxPipeline* (*RxLockedPipeUnlock)(RxLockedPipe* pipeline); // 
RwRaster* 	(*RwRasterCreate)(RwInt32 width, RwInt32 height, RwInt32 depth, RwInt32 flags); // 
RwBool 		(*RwRasterDestroy)(RwRaster* raster); // 
RwInt32 	(*RwRasterGetNumLevels)(RwRaster* raster); // 
RwRaster* 	(*RwRasterRenderFast)(RwRaster* raster, RwInt32 x, RwInt32 y); // 
RwRaster* 	(*RwRasterRender)(RwRaster* raster, RwInt32 x, RwInt32 y); // 
RwRaster* 	(*RwRasterPushContext)(RwRaster* raster); // 
RwRaster* 	(*RwRasterPopContext)(void); // 
RwRaster* 	(*RwRasterGetCurrentContext)(void); // 
RwRaster* 	(*RwRasterShowRaster)(RwRaster* raster, void* dev, RwUInt32 flags); // 
RwUInt8* 	(*RwRasterLock)(RwRaster* raster, RwUInt8 level, RwInt32 lockMode); // 
RwRaster* 	(*RwRasterUnlock)(RwRaster* raster); // 
RwUInt8* 	(*RwRasterLockPalette)(RwRaster* raster, RwInt32 lockMode); // 
RwInt32 	(*RwRasterRegisterPlugin)(RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB); // 
RxRenderStateVector* (*RxRenderStateVectorSetDefaultRenderStateVector)(RxRenderStateVector* rsvp); // 
RwImage* 	(*RwImageCreate)(RwInt32 width, RwInt32 height, RwInt32 depth); // 
RwBool 		(*RwImageDestroy)(RwImage* image); // 
RwImage* 	(*RwImageAllocatePixels)(RwImage* image); // 
RwImage* 	(*RwImageFreePixels)(RwImage* image); // 
RwImage* 	(*RwImageCopy)(RwImage* destImage, const RwImage* sourceImage); // 
RwImage* 	(*RwImageApplyMask)(RwImage* image, const RwImage* mask); // 
RwImage* 	(*RwImageMakeMask)(RwImage* image); // 
RwImage* 	(*RwImageReadMaskedImage)(const RwChar* imageName, const RwChar* maskname); // 
RwImage* 	(*RwImageRead)(const RwChar* imageName); // 
const RwChar* (*RwImageSetPath)(const RwChar* path); // 
RwBool 		(*RwImageSetGamma)(RwReal gammaValue); // 
RwImage* 	(*RwImageGammaCorrect)(RwImage* image); // 
const RwChar* (*RwImageFindFileType)(const RwChar* imageName); // 
RwBool 		(*RwTextureSetMipmapping)(RwBool enable); // 
RwBool 		(*RwTextureGetMipmapping)(void); // 
RwBool 		(*RwTextureSetAutoMipmapping)(RwBool enable); // 
RwBool 		(*RwTextureGetAutoMipmapping)(void); // 
RwBool 		(*RwTextureRasterGenerateMipmaps)(RwRaster* raster, RwImage* image); // 
RwTexture* 	(*RwTextureSetName)(RwTexture* texture, const RwChar* name); // 
RwTexture* 	(*RwTextureSetMaskName)(RwTexture* texture, const RwChar* maskName); // 
RwTexDictionary* (*RwTexDictionaryCreate)(void); // 
RwBool 		(*RwTexDictionaryDestroy)(RwTexDictionary* dict); // 
RwTexture* 	(*RwTextureCreate)(RwRaster* raster); // 
RwBool 		(*RwTextureDestroy)(RwTexture* texture); // 
RwTexture* 	(*RwTextureSetRaster)(RwTexture* texture, RwRaster* raster); // 
RwTexture* 	(*RwTexDictionaryAddTexture)(RwTexDictionary* dict, RwTexture* texture); // 
RwTexture* 	(*RwTexDictionaryFindNamedTexture)(RwTexDictionary* dict, const RwChar* name); // 
RwTexture* 	(*RwTextureRead)(const RwChar* name, const RwChar* maskName); // 
RwTexDictionary* (*RwTexDictionaryGetCurrent)(void); // 
RwTexDictionary* (*RwTexDictionarySetCurrent)(RwTexDictionary* dict); // 
const RwTexDictionary* (*RwTexDictionaryForAllTextures)(const RwTexDictionary* dict, RwTextureCallBack fpCallBack, void* pData); // 
RwInt32 	(*RwTextureRegisterPlugin)(RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB); // 
void* 		(*RwIm3DTransform)(RwIm3DVertex* pVerts, RwUInt32 numVerts, RwMatrix* ltm, RwUInt32 flags); // 
RwBool 		(*RwIm3DEnd)(void); // 
RwBool 		(*RwIm3DRenderLine)(RwInt32 vert1, RwInt32 vert2); // 
RwBool 		(*RwIm3DRenderIndexedPrimitive)(RwPrimitiveType primType, RwImVertexIndex* indices, RwInt32 numIndices); // 
RxPipeline* (*RwIm3DSetTransformPipeline)(RxPipeline* pipeline); // 
RxPipeline* (*RwIm3DSetRenderPipeline)(RxPipeline* pipeline, RwPrimitiveType primType); // 
RwBool 		(*_rwDeviceRegisterPlugin)(void); // 
RwImage* 	(*RwImageResample)(RwImage* dstImage, const RwImage* srcImage); // 
RwImage* 	(*RwImageCreateResample)(const RwImage* srcImage, RwInt32 width, RwInt32 height); // 
RwImage* 	(*RwImageSetFromRaster)(RwImage* image, RwRaster* raster); // 
RwRaster* 	(*RwRasterSetFromImage)(RwRaster* raster, RwImage* image); // 
RwImage* 	(*RwImageFindRasterFormat)(RwImage* ipImage, RwInt32 nRasterType, RwInt32* npWidth, RwInt32* npHeight, RwInt32* npDepth, RwInt32* npFormat); // 
RwFrame* 	(*RwFrameForAllObjects)(RwFrame* frame, RwObjectCallBack callBack, void* data); // 
RwFrame* 	(*RwFrameTranslate)(RwFrame* frame, const RwV3d* v, RwOpCombineType combine); // 
RwFrame* 	(*RwFrameRotate)(RwFrame* frame, const RwV3d* axis, RwReal angle, RwOpCombineType combine); // 
RwFrame* 	(*RwFrameScale)(RwFrame* frame, const RwV3d* v, RwOpCombineType combine); // 
RwFrame* 	(*RwFrameTransform)(RwFrame* frame, const RwMatrix* m, RwOpCombineType combine); // 
RwFrame* 	(*RwFrameOrthoNormalize)(RwFrame* frame); // 
RwBool 		(*RwFrameDestroyHierarchy)(RwFrame* frame); // 
RwFrame* 	(*RwFrameForAllChildren)(RwFrame* frame, RwFrameCallBack callBack, void* data); // 
RwFrame* 	(*RwFrameRemoveChild)(RwFrame* child); // 
RwFrame* 	(*RwFrameAddChild)(RwFrame* parent, RwFrame* child); // 
RwMatrix* 	(*RwFrameGetLTM)(RwFrame* frame); // 
RwFrame* 	(*RwFrameUpdateObjects)(RwFrame* frame); // 
RwFrame* 	(*RwFrameCreate)(void); // 
RwBool 		(*RwFrameDestroy)(RwFrame* frame); // 
RwBool 		(*RwFrameDirty)(const RwFrame* frame); // 
RwInt32 	(*RwFrameRegisterPlugin)(RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB); // 
RwFrame* 	(*_rwFrameCloneAndLinkClones)(RwFrame* root); // 
RwFrame* 	(*_rwFramePurgeClone)(RwFrame* root); // 
void 		(*_rwObjectHasFrameSetFrame)(void* object, RwFrame* frame); // 
void 		(*_rwObjectHasFrameReleaseFrame)(void); // 
RwInt32 	(*RwTextureRegisterPluginStream)(RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB); // 
RwUInt32 	(*RwTextureStreamGetSize)(const RwTexture* texture); // 
RwTexture* 	(*RwTextureStreamRead)(RwStream* stream); // 
const RwTexture* (*RwTextureStreamWrite)(const RwTexture* texture, RwStream* stream); // 
RwTexDictionary* (*RwTexDictionaryStreamRead)(RwStream* stream); // 
const RwTexDictionary* (*RwTexDictionaryStreamWrite)(const RwTexDictionary* texDict, RwStream* stream); // 
RwInt32 	(*RwFrameRegisterPluginStream)(RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB); // 
rwFrameList* (*_rwFrameListDeinitialize)(rwFrameList* frameList); // 
rwFrameList* (*_rwFrameListStreamRead)(RwStream* stream, rwFrameList* fl); // 
RwBBox* 	(*RwBBoxCalculate)(RwBBox* boundBox, const RwV3d* verts, RwInt32 numVerts); // 
RwCamera* 	(*RwCameraBeginUpdate)(RwCamera* camera); // 
RwCamera* 	(*RwCameraEndUpdate)(RwCamera* camera); // 
RwCamera* 	(*RwCameraClear)(RwCamera* camera, RwRGBA* colour, RwInt32 clearMode); // 
RwCamera* 	(*RwCameraShowRaster)(RwCamera* camera, void* pDev, RwUInt32 flags); // 
RwBool 		(*RwCameraDestroy)(RwCamera* camera); // 
RwCamera* 	(*RwCameraCreate)(void); // 
RwCamera* 	(*RwCameraSetViewOffset)(RwCamera* camera, const RwV2d* offset); // 
RwCamera* 	(*RwCameraSetViewWindow)(RwCamera* camera, const RwV2d* viewWindow); // 
RwCamera* 	(*RwCameraSetProjection)(RwCamera* camera, RwCameraProjection projection); // 
RwCamera* 	(*RwCameraSetNearClipPlane)(RwCamera* camera, RwReal nearClip); // 
RwCamera* 	(*RwCameraSetFarClipPlane)(RwCamera* camera, RwReal farClip); // 
RwInt32 	(*RwCameraRegisterPlugin)(RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB); // 
RwFrustumTestResult (*RwCameraFrustumTestSphere)(const RwCamera* camera, const RwSphere* sphere); // 
RwCamera* 	(*RwCameraStreamRead)(RwStream* stream); // 

void InitRenderWareFuncs()
{
	RsGlobal = (RsGlobalType*)(g_libGTAVC+0x6F5660);

	/* rwplcore.h */
	*(void **)(&RwStreamOpen) = (void*)(g_libGTAVC+0x28F768+1);

	/* rwcore.h */
	*(void **)(&RxHeapCreate) = (void*)(g_libGTAVC+0x28C04C+1);
}