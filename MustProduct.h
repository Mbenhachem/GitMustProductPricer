#pragma once
#include <ql/termstructures/yieldtermstructure.hpp>
using namespace QuantLib;

class MustProduct
{
public:
	virtual ~MustProduct()
	{
	}

	MustProduct();

	//Param�tres

	virtual double Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure) = 0;
};

class MustVanilleSwap : public MustProduct
{
	double Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure) override;
	//param�tres
	//Notionnel
	Real nominal;
	Date settlementDate;
	Date maturity;
	//FixedLeg
	Frequency fixedLegFrequency;
	DayCounter fixedLegDayCounter;
	Rate fixedRate;
	//FloatingLeg
	DayCounter floatingLegDayCounter;
	Frequency floatingLegFrequency;


};

