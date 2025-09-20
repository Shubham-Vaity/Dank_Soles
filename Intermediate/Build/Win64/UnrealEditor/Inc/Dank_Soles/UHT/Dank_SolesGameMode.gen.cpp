// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Dank_Soles/Dank_SolesGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDank_SolesGameMode() {}

// Begin Cross Module References
DANK_SOLES_API UClass* Z_Construct_UClass_ADank_SolesGameMode();
DANK_SOLES_API UClass* Z_Construct_UClass_ADank_SolesGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_Dank_Soles();
// End Cross Module References

// Begin Class ADank_SolesGameMode
void ADank_SolesGameMode::StaticRegisterNativesADank_SolesGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADank_SolesGameMode);
UClass* Z_Construct_UClass_ADank_SolesGameMode_NoRegister()
{
	return ADank_SolesGameMode::StaticClass();
}
struct Z_Construct_UClass_ADank_SolesGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Dank_SolesGameMode.h" },
		{ "ModuleRelativePath", "Dank_SolesGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADank_SolesGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ADank_SolesGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Dank_Soles,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADank_SolesGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADank_SolesGameMode_Statics::ClassParams = {
	&ADank_SolesGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADank_SolesGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ADank_SolesGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADank_SolesGameMode()
{
	if (!Z_Registration_Info_UClass_ADank_SolesGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADank_SolesGameMode.OuterSingleton, Z_Construct_UClass_ADank_SolesGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADank_SolesGameMode.OuterSingleton;
}
template<> DANK_SOLES_API UClass* StaticClass<ADank_SolesGameMode>()
{
	return ADank_SolesGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADank_SolesGameMode);
ADank_SolesGameMode::~ADank_SolesGameMode() {}
// End Class ADank_SolesGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Dank_Soles_Source_Dank_Soles_Dank_SolesGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADank_SolesGameMode, ADank_SolesGameMode::StaticClass, TEXT("ADank_SolesGameMode"), &Z_Registration_Info_UClass_ADank_SolesGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADank_SolesGameMode), 2617858916U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Dank_Soles_Source_Dank_Soles_Dank_SolesGameMode_h_2413212719(TEXT("/Script/Dank_Soles"),
	Z_CompiledInDeferFile_FID_Dank_Soles_Source_Dank_Soles_Dank_SolesGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Dank_Soles_Source_Dank_Soles_Dank_SolesGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
