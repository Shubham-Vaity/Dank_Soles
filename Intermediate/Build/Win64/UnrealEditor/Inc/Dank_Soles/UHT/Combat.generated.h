// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Combat.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DANK_SOLES_Combat_generated_h
#error "Combat.generated.h already included, missing '#pragma once' in Combat.h"
#endif
#define DANK_SOLES_Combat_generated_h

#define FID_Dank_Soles_Source_Dank_Soles_Combat_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execPerformLookSphereTrace);


#define FID_Dank_Soles_Source_Dank_Soles_Combat_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCombat(); \
	friend struct Z_Construct_UClass_UCombat_Statics; \
public: \
	DECLARE_CLASS(UCombat, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Dank_Soles"), NO_API) \
	DECLARE_SERIALIZER(UCombat)


#define FID_Dank_Soles_Source_Dank_Soles_Combat_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCombat(UCombat&&); \
	UCombat(const UCombat&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCombat); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCombat); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCombat) \
	NO_API virtual ~UCombat();


#define FID_Dank_Soles_Source_Dank_Soles_Combat_h_14_PROLOG
#define FID_Dank_Soles_Source_Dank_Soles_Combat_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Dank_Soles_Source_Dank_Soles_Combat_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Dank_Soles_Source_Dank_Soles_Combat_h_17_INCLASS_NO_PURE_DECLS \
	FID_Dank_Soles_Source_Dank_Soles_Combat_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DANK_SOLES_API UClass* StaticClass<class UCombat>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Dank_Soles_Source_Dank_Soles_Combat_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
