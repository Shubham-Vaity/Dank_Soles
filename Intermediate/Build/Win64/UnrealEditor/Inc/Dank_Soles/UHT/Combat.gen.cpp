// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Dank_Soles/Combat.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCombat() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
DANK_SOLES_API UClass* Z_Construct_UClass_UCombat();
DANK_SOLES_API UClass* Z_Construct_UClass_UCombat_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Dank_Soles();
// End Cross Module References

// Begin Class UCombat Function checkForEnemy
struct Z_Construct_UFunction_UCombat_checkForEnemy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Combat.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombat_checkForEnemy_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombat, nullptr, "checkForEnemy", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombat_checkForEnemy_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCombat_checkForEnemy_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UCombat_checkForEnemy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombat_checkForEnemy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCombat::execcheckForEnemy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->checkForEnemy();
	P_NATIVE_END;
}
// End Class UCombat Function checkForEnemy

// Begin Class UCombat Function PerformLookSphereTrace
struct Z_Construct_UFunction_UCombat_PerformLookSphereTrace_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Combat.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombat_PerformLookSphereTrace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombat, nullptr, "PerformLookSphereTrace", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombat_PerformLookSphereTrace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCombat_PerformLookSphereTrace_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UCombat_PerformLookSphereTrace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombat_PerformLookSphereTrace_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCombat::execPerformLookSphereTrace)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PerformLookSphereTrace();
	P_NATIVE_END;
}
// End Class UCombat Function PerformLookSphereTrace

// Begin Class UCombat
void UCombat::StaticRegisterNativesUCombat()
{
	UClass* Class = UCombat::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "checkForEnemy", &UCombat::execcheckForEnemy },
		{ "PerformLookSphereTrace", &UCombat::execPerformLookSphereTrace },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCombat);
UClass* Z_Construct_UClass_UCombat_NoRegister()
{
	return UCombat::StaticClass();
}
struct Z_Construct_UClass_UCombat_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Combat.h" },
		{ "ModuleRelativePath", "Combat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_playerReff_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Combat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyReff_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Combat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Dot_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Combat.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Dotreff_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Combat.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_playerReff;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyReff;
	static const UECodeGen_Private::FClassPropertyParams NewProp_Dot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Dotreff;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCombat_checkForEnemy, "checkForEnemy" }, // 3406416037
		{ &Z_Construct_UFunction_UCombat_PerformLookSphereTrace, "PerformLookSphereTrace" }, // 1743255002
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCombat>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombat_Statics::NewProp_playerReff = { "playerReff", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCombat, playerReff), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_playerReff_MetaData), NewProp_playerReff_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombat_Statics::NewProp_EnemyReff = { "EnemyReff", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCombat, EnemyReff), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyReff_MetaData), NewProp_EnemyReff_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UCombat_Statics::NewProp_Dot = { "Dot", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCombat, Dot), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Dot_MetaData), NewProp_Dot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombat_Statics::NewProp_Dotreff = { "Dotreff", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCombat, Dotreff), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Dotreff_MetaData), NewProp_Dotreff_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCombat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombat_Statics::NewProp_playerReff,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombat_Statics::NewProp_EnemyReff,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombat_Statics::NewProp_Dot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombat_Statics::NewProp_Dotreff,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCombat_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCombat_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Dank_Soles,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCombat_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCombat_Statics::ClassParams = {
	&UCombat::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCombat_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCombat_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCombat_Statics::Class_MetaDataParams), Z_Construct_UClass_UCombat_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCombat()
{
	if (!Z_Registration_Info_UClass_UCombat.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCombat.OuterSingleton, Z_Construct_UClass_UCombat_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCombat.OuterSingleton;
}
template<> DANK_SOLES_API UClass* StaticClass<UCombat>()
{
	return UCombat::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCombat);
UCombat::~UCombat() {}
// End Class UCombat

// Begin Registration
struct Z_CompiledInDeferFile_FID_Dank_Soles_Source_Dank_Soles_Combat_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCombat, UCombat::StaticClass, TEXT("UCombat"), &Z_Registration_Info_UClass_UCombat, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCombat), 3628551330U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dank_Soles_Source_Dank_Soles_Combat_h_1301057552(TEXT("/Script/Dank_Soles"),
	Z_CompiledInDeferFile_FID_Dank_Soles_Source_Dank_Soles_Combat_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Dank_Soles_Source_Dank_Soles_Combat_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
