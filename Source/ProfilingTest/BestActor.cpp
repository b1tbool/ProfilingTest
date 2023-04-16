// ReSharper disable CommentTypo
#include "BestActor.h"
#include "Components/CapsuleComponent.h"

// Объявление группы, где:
// L"BestActor"				Название группы
// STATGROUP_BestActor		Ярлык группы (STATGROUP_ обязательно!)
// STATCAT_Advanced			Анрилкой не используется, оставляем по умолчанию
DECLARE_STATS_GROUP(L"BestActor", STATGROUP_BestActor, STATCAT_Advanced);

// Объявление статистики, где:
// L"GoodBeginOverlap"		Название статистики
// STAT_GoodBeginOverlap	Ярлык статистики (STAT_ обязательно!)
// STATGROUP_BestActor		Ярлык группы
DECLARE_CYCLE_STAT(L"GoodBeginOverlap", STAT_GoodBeginOverlap, STATGROUP_BestActor);
DECLARE_CYCLE_STAT(L"GoodMathFunction", STAT_GoodMathFunction, STATGROUP_BestActor);

// Объявление счётчика, где:
// L"GoodCycleCounter"		Название счётчика
// STAT_GoodCycleCounter	Ярлык счётчика (STAT_ обязательно!)
// STATGROUP_BestActor		Ярлык группы
DECLARE_DWORD_ACCUMULATOR_STAT(L"GoodCycleCounter", STAT_GoodCycleCounter, STATGROUP_BestActor);

ABestActor::ABestActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SMComponent = CreateDefaultSubobject<UStaticMeshComponent>("SMComponent");
	ensure(SMComponent);
	SMComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SMComponent->SetCollisionObjectType(ECC_WorldDynamic);
	SMComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	SMComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SMComponent->OnComponentBeginOverlap.AddDynamic(this, &ABestActor::GoodBeginOverlap);
}

void ABestActor::GoodBeginOverlap(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor,
	UPrimitiveComponent* InOtherComponent, int32 InOtherBodyIndex, bool IsFromSweep, const FHitResult& InSweepResult)
{
	if (!InOtherActor || !Cast<UCapsuleComponent>(InOtherComponent)) return;

	// Установка значения счётчика.
	SET_DWORD_STAT(STAT_GoodCycleCounter, 0);
	// Замеры производительности GoodBeginOverlap.
	SCOPE_CYCLE_COUNTER(STAT_GoodBeginOverlap);

	for (int LIndex = 0; LIndex < CycleCount; ++LIndex)
	{
		// Инкремент GoodCycleCounter.
		INC_DWORD_STAT(STAT_GoodCycleCounter);
		GoodMathFunction();
	}

	Calculations = 0.f;
}

void ABestActor::GoodMathFunction()
{
	// Замеры производительности GoodMathFunction.
	SCOPE_CYCLE_COUNTER(STAT_GoodMathFunction);

	const float LAtan2 = FMath::Atan2(FMath::FRandRange(0.f, 1.f), FMath::FRandRange(0.f, 1.f));
	const float LPow = FMath::Pow(FMath::FRandRange(2.f, 5.f), FMath::FRandRange(2.f, 5.f));

	Calculations = LAtan2 * 2.f + LPow;
}