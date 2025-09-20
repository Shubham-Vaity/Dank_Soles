// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Dank_SolesCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInputActionValue;
#ifdef DANK_SOLES_Dank_SolesCharacter_generated_h
#error "Dank_SolesCharacter.generated.h already included, missing '#pragma once' in Dank_SolesCharacter.h"
#endif
#define DANK_SOLES_Dank_SolesCharacter_generated_h

#define FID_Dank_Soles_Source_Dank_Soles_Dank_SolesCharacter_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execLockTraget);


#define FID_Dank_Soles_Source_Dank_Soles_Dank_SolesCharacter_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADank_SolesCharacter(); \
	friend struct Z_Construct_UClass_ADank_SolesCharacter_Statics; \
public: \
	DECLARE_CLASS(ADank_SolesCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Dank_Soles"), NO_API) \
	DECLARE_SERIALIZER(ADank_SolesCharacter)


#define FID_Dank_Soles_Source_Dank_Soles_Dank_SolesCharacter_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADank_SolesCharacter(ADank_SolesCharacter&&); \
	ADank_SolesCharacter(const ADank_SolesCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADank_SolesCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADank_SolesCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADank_SolesCharacter) \
	NO_API virtual ~ADank_SolesCharacter();


#define FID_Dank_Soles_Source_Dank_Soles_Dank_SolesCharacter_h_20_PROLOG
#define FID_Dank_Soles_Source_Dank_Soles_Dank_SolesCharacter_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Dank_Soles_Source_Dank_Soles_Dank_SolesCharacter_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Dank_Soles_Source_Dank_Soles_Dank_SolesCharacter_h_23_INCLASS_NO_PURE_DECLS \
	FID_Dank_Soles_Source_Dank_Soles_Dank_SolesCharacter_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DANK_SOLES_API UClass* StaticClass<class ADank_SolesCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Dank_Soles_Source_Dank_Soles_Dank_SolesCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
