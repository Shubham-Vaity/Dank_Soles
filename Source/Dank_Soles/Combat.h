

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Dank_SolesCharacter.h"
#include "Combat.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DANK_SOLES_API UCombat : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	UCombat();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	ACharacter* playerReff;



	
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Lock();


private:

};
