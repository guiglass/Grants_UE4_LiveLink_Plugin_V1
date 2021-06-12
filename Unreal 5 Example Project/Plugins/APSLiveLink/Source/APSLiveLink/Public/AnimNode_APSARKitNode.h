// Copyright 2021 Animation Prep Studios. All Rights Reserved.

#pragma once

#include "Animation/AnimNodeBase.h"
#include "BoneContainer.h"
#include "APSMocapServerSync.h"
#include "AnimNode_APSARKitNode.generated.h"

USTRUCT()
struct FBoneRef
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "Settings")
		FBoneReference Bone;
};

USTRUCT(BlueprintType)
struct APSLIVELINK_API FAnimNode_APSARKitNode : public FAnimNode_Base
{
	// The APS motion capture data sync custom animation node.
	GENERATED_BODY()
	
	TArray<SmartName::UID_Type> blendshapeCurveMap;
	TArray<float> blendshapeValuesMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings (APS Live-Link)")
	FPoseLink BasePose;

public:
	FAnimNode_APSARKitNode();

	// FAnimNode_Base interface
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext & Output) override;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;
	//virtual void EvaluateComponentSpace_AnyThread(FComponentSpacePoseContext& Output) override;
	// End of FAnimNode_Base interface
};