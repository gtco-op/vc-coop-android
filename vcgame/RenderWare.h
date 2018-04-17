/* source: https://github.com/DK22Pac/plugin-sdk */

#pragma once

// TODO: Clean up RW headers

#include "rw/rwcore.h"
#include "rw/skeleton.h"

extern RsGlobalType* RsGlobal;

/* rwplcore.h */

extern RwStream* 	(*RwStreamOpen)(RwStreamType type, RwStreamAccessType accessType, const void* pData);
extern RwBool 		(*RwStreamClose)(RwStream* stream, void* pData);
extern RwUInt32 	(*RwStreamRead)(RwStream* stream, void* buffer, RwUInt32 length);
extern RwStream* 	(*RwStreamWrite)(RwStream* stream, const void* buffer, RwUInt32 length);
extern RwStream* 	(*RwStreamSkip)(RwStream* stream, RwUInt32 offset);
extern RwBool 		(*RwMatrixDestroy)(RwMatrix* mpMat);
extern RwMatrix* 	(*RwMatrixCreate)(void);
extern RwMatrix* 	(*RwMatrixMultiply)(RwMatrix* matrixOut, const RwMatrix* MatrixIn1, const RwMatrix* matrixIn2); 
extern RwMatrix* 	(*RwMatrixTransform)(RwMatrix* matrix, const RwMatrix* transform, RwOpCombineType combineOp); 
extern RwMatrix* 	(*RwMatrixOrthoNormalize)(RwMatrix* matrixOut, const RwMatrix* matrixIn); // 
extern RwMatrix* 	(*RwMatrixInvert)(RwMatrix* matrixOut, const RwMatrix* matrixIn); // 
extern RwMatrix* 	(*RwMatrixScale)(RwMatrix* matrix, const RwV3d* scale, RwOpCombineType combineOp); // 
extern RwMatrix* 	(*RwMatrixTranslate)(RwMatrix* matrix, const RwV3d* translation, RwOpCombineType combineOp); // 
extern RwMatrix* 	(*RwMatrixRotate)(RwMatrix* matrix, const RwV3d* axis, RwReal angle, RwOpCombineType combineOp); // 
extern RwMatrix* 	(*RwMatrixRotateOneMinusCosineSine)(RwMatrix* matrix, const RwV3d* unitAxis, RwReal oneMinusCosine, RwReal sine, RwOpCombineType combineOp); // 
extern RwMatrix* 	(*RwMatrixUpdate)(RwMatrix* matrix); // 
extern RwMatrix* 	(*RwMatrixOptimize)(RwMatrix* matrix, const RwMatrixTolerance* tolerance); // 
extern RwReal 		(*_rwMatrixDeterminant)(const RwMatrix* matrix); // 
extern RwReal 		(*_rwMatrixNormalError)(const RwMatrix* matrix); // 
extern RwReal 		(*_rwMatrixOrthogonalError)(const RwMatrix* matrix); // 
extern RwReal 		(*_rwMatrixIdentityError)(const RwMatrix* matrix); // 
extern RwReal 		(*RwV3dNormalize)(RwV3d* out, const RwV3d* in); // 
extern RwReal 		(*RwV3dLength)(const RwV3d* in); // 
extern RwV3d* 		(*RwV3dTransformPoints)(RwV3d* pointsOut, const RwV3d* pointsIn, RwInt32 numPoints, const RwMatrix* matrix); // 
extern RwV3d* 		(*RwV3dTransformVectors)(RwV3d* vectorsOut, const RwV3d* vectorsIn, RwInt32 numPoints, const RwMatrix* matrix); // 
extern RwReal 		(*_rwSqrt)(const RwReal num); // 
extern RwReal 		(*_rwInvSqrt)(const RwReal num); // 
extern RwReal 		(*RwIm2DGetNearScreenZ)(void); // 
extern RwReal 		(*RwIm2DGetFarScreenZ)(void); // 
extern RwBool 		(*RwRenderStateGet)(RwRenderState state, void* value); // 
extern RwBool 		(*RwRenderStateSet)(RwRenderState state, void* value); // 
extern RwBool 		(*RwIm2DRenderLine)(RwIm2DVertex* vertices, RwInt32 numVertices, RwInt32 vert1, RwInt32 vert2); // 
extern RwBool 		(*RwIm2DRenderPrimitive)(RwPrimitiveType primType, RwIm2DVertex* vertices, RwInt32 numVertices); // 
extern RwBool 		(*RwIm2DRenderIndexedPrimitive)(RwPrimitiveType primType, RwIm2DVertex* vertices, RwInt32 numVertices, RwImVertexIndex* indices, RwInt32 numIndices); // 
extern RwFileFunctions* (*RwOsGetFileInterface)(void); // 
extern RwError* 	(*RwErrorGet)(RwError* code); // 
extern RwError* 	(*RwErrorSet)(RwError* code); // 
extern RwInt32 		(*_rwerror)(RwInt32 code, ...); // 
extern RwBool 		(*RwResourcesEmptyArena)(void); // 
extern RwResEntry* 	(*RwResourcesAllocateResEntry)(void* owner, RwResEntry* ownerRef, RwInt32 size, RwResEntryDestroyNotify destroyNotify); // 
extern RwBool 		(*RwResourcesFreeResEntry)(RwResEntry* entry); // 
extern void 		(*_rwResourcesPurge)(void); // 
extern RwBool 		(*RwStreamFindChunk)(RwStream* stream, RwUInt32 type, RwUInt32* lengthOut, RwUInt32* versionOut); // 
extern RwStream* 	(*_rwStreamWriteVersionedChunkHeader)(RwStream* stream, RwInt32 type, RwInt32 size, RwUInt32 version, RwUInt32 buildNum); // 
extern RwStream* 	(*RwStreamWriteReal)(RwStream* stream, const RwReal* reals, RwUInt32 numBytes); // 
extern RwStream* 	(*RwStreamWriteInt32)(RwStream* stream, const RwInt32* ints, RwUInt32 numBytes); // 
extern RwStream* 	(*RwStreamReadReal)(RwStream* stream, RwReal* reals, RwUInt32 numBytes); // 
extern RwStream* 	(*RwStreamReadInt32)(RwStream* stream, RwInt32* ints, RwUInt32 numBytes); // 

/* rwcore.h */

extern RxHeap* 		(*RxHeapCreate)(RwUInt32 size); // 
extern void 		(*RxHeapDestroy)(RxHeap* heap); // 
extern RwBool 		(*_rxHeapReset)(RxHeap* heap); // 
extern void* 		(*RxHeapAlloc)(RxHeap* heap, RwUInt32 size); // 
extern void 		(*RxHeapFree)(RxHeap* heap, void* block); // 
extern RwBool 		(*_rxPipelineOpen)(void); // 
extern RwBool 		(*_rxPipelineClose)(void); // 
extern RxPipeline* 	(*RxPipelineCreate)(void); // 
extern void 		(*_rxPipelineDestroy)(RxPipeline* Pipeline); // 
extern RxHeap* 		(*RxHeapGetGlobalHeap)(void); // 
extern RxPipeline* 	(*RxPipelineExecute)(RxPipeline* pipeline, void* data, RwBool heapReset); // 
extern void 		(*_rxPacketDestroy)(RxPacket* Packet); // 
extern RxPipelineNode* (*RxPipelineFindNodeByName)(RxPipeline* pipeline, const RwChar* name, RxPipelineNode* start, RwInt32* nodeIndex); // 
extern RxLockedPipe* (*RxPipelineLock)(RxPipeline* pipeline); // 
extern RxPipeline* (*RxLockedPipeUnlock)(RxLockedPipe* pipeline); // 
extern RwRaster* 	(*RwRasterCreate)(RwInt32 width, RwInt32 height, RwInt32 depth, RwInt32 flags); // 
extern RwBool 		(*RwRasterDestroy)(RwRaster* raster); // 
extern RwInt32 		(*RwRasterGetNumLevels)(RwRaster* raster); // 
extern RwRaster* 	(*RwRasterRenderFast)(RwRaster* raster, RwInt32 x, RwInt32 y); // 
extern RwRaster* 	(*RwRasterRender)(RwRaster* raster, RwInt32 x, RwInt32 y); // 
extern RwRaster* 	(*RwRasterPushContext)(RwRaster* raster); // 
extern RwRaster* 	(*RwRasterPopContext)(void); // 
extern RwRaster* 	(*RwRasterGetCurrentContext)(void); // 
extern RwRaster* 	(*RwRasterShowRaster)(RwRaster* raster, void* dev, RwUInt32 flags); // 
extern RwUInt8* 	(*RwRasterLock)(RwRaster* raster, RwUInt8 level, RwInt32 lockMode); // 
extern RwRaster* 	(*RwRasterUnlock)(RwRaster* raster); // 
extern RwUInt8* 	(*RwRasterLockPalette)(RwRaster* raster, RwInt32 lockMode); // 
extern RwInt32 	(*RwRasterRegisterPlugin)(RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB); // 
extern RxRenderStateVector* (*RxRenderStateVectorSetDefaultRenderStateVector)(RxRenderStateVector* rsvp); // 
extern RwImage* 	(*RwImageCreate)(RwInt32 width, RwInt32 height, RwInt32 depth); // 
extern RwBool 		(*RwImageDestroy)(RwImage* image); // 
extern RwImage* 	(*RwImageAllocatePixels)(RwImage* image); // 
extern RwImage* 	(*RwImageFreePixels)(RwImage* image); // 
extern RwImage* 	(*RwImageCopy)(RwImage* destImage, const RwImage* sourceImage); // 
extern RwImage* 	(*RwImageApplyMask)(RwImage* image, const RwImage* mask); // 
extern RwImage* 	(*RwImageMakeMask)(RwImage* image); // 
extern RwImage* 	(*RwImageReadMaskedImage)(const RwChar* imageName, const RwChar* maskname); // 
extern RwImage* 	(*RwImageRead)(const RwChar* imageName); // 
extern const RwChar* (*RwImageSetPath)(const RwChar* path); // 
extern RwBool 		(*RwImageSetGamma)(RwReal gammaValue); // 
extern RwImage* 	(*RwImageGammaCorrect)(RwImage* image); // 
extern const RwChar* (*RwImageFindFileType)(const RwChar* imageName); // 
extern RwBool 		(*RwTextureSetMipmapping)(RwBool enable); // 
extern RwBool 		(*RwTextureGetMipmapping)(void); // 
extern RwBool 		(*RwTextureSetAutoMipmapping)(RwBool enable); // 
extern RwBool 		(*RwTextureGetAutoMipmapping)(void); // 
extern RwBool 		(*RwTextureRasterGenerateMipmaps)(RwRaster* raster, RwImage* image); // 
extern RwTexture* 	(*RwTextureSetName)(RwTexture* texture, const RwChar* name); // 
extern RwTexture* 	(*RwTextureSetMaskName)(RwTexture* texture, const RwChar* maskName); // 
extern RwTexDictionary* (*RwTexDictionaryCreate)(void); // 
extern RwBool 		(*RwTexDictionaryDestroy)(RwTexDictionary* dict); // 
extern RwTexture* 	(*RwTextureCreate)(RwRaster* raster); // 
extern RwBool 		(*RwTextureDestroy)(RwTexture* texture); // 
extern RwTexture* 	(*RwTextureSetRaster)(RwTexture* texture, RwRaster* raster); // 
extern RwTexture* 	(*RwTexDictionaryAddTexture)(RwTexDictionary* dict, RwTexture* texture); // 
extern RwTexture* 	(*RwTexDictionaryFindNamedTexture)(RwTexDictionary* dict, const RwChar* name); // 
extern RwTexture* 	(*RwTextureRead)(const RwChar* name, const RwChar* maskName); // 
extern RwTexDictionary* (*RwTexDictionaryGetCurrent)(void); // 
extern RwTexDictionary* (*RwTexDictionarySetCurrent)(RwTexDictionary* dict); // 
extern const RwTexDictionary* (*RwTexDictionaryForAllTextures)(const RwTexDictionary* dict, RwTextureCallBack fpCallBack, void* pData); // 
extern RwInt32 	(*RwTextureRegisterPlugin)(RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB); // 
extern void* 		(*RwIm3DTransform)(RwIm3DVertex* pVerts, RwUInt32 numVerts, RwMatrix* ltm, RwUInt32 flags); // 
extern RwBool 		(*RwIm3DEnd)(void); // 
extern RwBool 		(*RwIm3DRenderLine)(RwInt32 vert1, RwInt32 vert2); // 
extern RwBool 		(*RwIm3DRenderIndexedPrimitive)(RwPrimitiveType primType, RwImVertexIndex* indices, RwInt32 numIndices); // 
extern RxPipeline* 	(*RwIm3DSetTransformPipeline)(RxPipeline* pipeline); // 
extern RxPipeline* 	(*RwIm3DSetRenderPipeline)(RxPipeline* pipeline, RwPrimitiveType primType); // 
extern RwBool 		(*_rwDeviceRegisterPlugin)(void); // 
extern RwImage* 	(*RwImageResample)(RwImage* dstImage, const RwImage* srcImage); // 
extern RwImage* 	(*RwImageCreateResample)(const RwImage* srcImage, RwInt32 width, RwInt32 height); // 
extern RwImage* 	(*RwImageSetFromRaster)(RwImage* image, RwRaster* raster); // 
extern RwRaster* 	(*RwRasterSetFromImage)(RwRaster* raster, RwImage* image); // 
extern RwImage* 	(*RwImageFindRasterFormat)(RwImage* ipImage, RwInt32 nRasterType, RwInt32* npWidth, RwInt32* npHeight, RwInt32* npDepth, RwInt32* npFormat); // 
extern RwFrame* 	(*RwFrameForAllObjects)(RwFrame* frame, RwObjectCallBack callBack, void* data); // 
extern RwFrame* 	(*RwFrameTranslate)(RwFrame* frame, const RwV3d* v, RwOpCombineType combine); // 
extern RwFrame* 	(*RwFrameRotate)(RwFrame* frame, const RwV3d* axis, RwReal angle, RwOpCombineType combine); // 
extern RwFrame* 	(*RwFrameScale)(RwFrame* frame, const RwV3d* v, RwOpCombineType combine); // 
extern RwFrame* 	(*RwFrameTransform)(RwFrame* frame, const RwMatrix* m, RwOpCombineType combine); // 
extern RwFrame* 	(*RwFrameOrthoNormalize)(RwFrame* frame); // 
extern RwBool 		(*RwFrameDestroyHierarchy)(RwFrame* frame); // 
extern RwFrame* 	(*RwFrameForAllChildren)(RwFrame* frame, RwFrameCallBack callBack, void* data); // 
extern RwFrame* 	(*RwFrameRemoveChild)(RwFrame* child); // 
extern RwFrame* 	(*RwFrameAddChild)(RwFrame* parent, RwFrame* child); // 
extern RwMatrix* 	(*RwFrameGetLTM)(RwFrame* frame); // 
extern RwFrame* 	(*RwFrameUpdateObjects)(RwFrame* frame); // 
extern RwFrame* 	(*RwFrameCreate)(void); // 
extern RwBool 		(*RwFrameDestroy)(RwFrame* frame); // 
extern RwBool 		(*RwFrameDirty)(const RwFrame* frame); // 
extern RwInt32 		(*RwFrameRegisterPlugin)(RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB); // 
extern RwFrame* 	(*_rwFrameCloneAndLinkClones)(RwFrame* root); // 
extern RwFrame* 	(*_rwFramePurgeClone)(RwFrame* root); // 
extern void 		(*_rwObjectHasFrameSetFrame)(void* object, RwFrame* frame); // 
extern void 		(*_rwObjectHasFrameReleaseFrame)(void); // 
extern RwInt32 		(*RwTextureRegisterPluginStream)(RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB); // 
extern RwUInt32 	(*RwTextureStreamGetSize)(const RwTexture* texture); // 
extern RwTexture* 	(*RwTextureStreamRead)(RwStream* stream); // 
extern const RwTexture* (*RwTextureStreamWrite)(const RwTexture* texture, RwStream* stream); // 
extern RwTexDictionary* (*RwTexDictionaryStreamRead)(RwStream* stream); // 
extern const RwTexDictionary* (*RwTexDictionaryStreamWrite)(const RwTexDictionary* texDict, RwStream* stream); // 
extern RwInt32 		(*RwFrameRegisterPluginStream)(RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB); // 
extern rwFrameList* (*_rwFrameListDeinitialize)(rwFrameList* frameList); // 
extern rwFrameList* (*_rwFrameListStreamRead)(RwStream* stream, rwFrameList* fl); // 
extern RwBBox* 		(*RwBBoxCalculate)(RwBBox* boundBox, const RwV3d* verts, RwInt32 numVerts); // 
extern RwCamera* 	(*RwCameraBeginUpdate)(RwCamera* camera); // 
extern RwCamera* 	(*RwCameraEndUpdate)(RwCamera* camera); // 
extern RwCamera* 	(*RwCameraClear)(RwCamera* camera, RwRGBA* colour, RwInt32 clearMode); // 
extern RwCamera* 	(*RwCameraShowRaster)(RwCamera* camera, void* pDev, RwUInt32 flags); // 
extern RwBool 		(*RwCameraDestroy)(RwCamera* camera); // 
extern RwCamera* 	(*RwCameraCreate)(void); // 
extern RwCamera* 	(*RwCameraSetViewOffset)(RwCamera* camera, const RwV2d* offset); // 
extern RwCamera* 	(*RwCameraSetViewWindow)(RwCamera* camera, const RwV2d* viewWindow); // 
extern RwCamera* 	(*RwCameraSetProjection)(RwCamera* camera, RwCameraProjection projection); // 
extern RwCamera* 	(*RwCameraSetNearClipPlane)(RwCamera* camera, RwReal nearClip); // 
extern RwCamera* 	(*RwCameraSetFarClipPlane)(RwCamera* camera, RwReal farClip); // 
extern RwInt32 	(*RwCameraRegisterPlugin)(RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB); // 
extern RwFrustumTestResult (*RwCameraFrustumTestSphere)(const RwCamera* camera, const RwSphere* sphere); // 
extern RwCamera* 	(*RwCameraStreamRead)(RwStream* stream); // 

#define RWRSTATE(a) (reinterpret_cast<void *>(a))