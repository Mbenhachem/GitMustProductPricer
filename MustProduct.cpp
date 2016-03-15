#include "MustProduct.h"
#include <ql/quantlib.hpp>
#include "SwapFixedLeg.h"
#include "SwapFloatingLeg.h"


using namespace std;
using namespace QuantLib;
using namespace boost;

MustProduct::MustProduct()
{
}

MustVanilleSwap::MustVanilleSwap(Real nominal, Date settlementDate, Date maturity, Frequency fixedLegFrequency, DayCounter fixedLegDayCounter, Rate fixedRate, DayCounter floatingLegDayCounter, Frequency floatingLegFrequency)
:nominal(nominal), settlementDate(settlementDate), maturity(maturity), fixedLegFrequency(fixedLegFrequency), fixedLegDayCounter(fixedLegDayCounter), fixedRate(fixedRate), floatingLegDayCounter(floatingLegDayCounter), floatingLegFrequency(floatingLegFrequency)
{
}

double MustVanilleSwap::Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure)
{
	//SetParamètre
		//index
	boost::shared_ptr<IborIndex> euribor(new Euribor(3 * Months, forwardingTermStructure));
	euribor->addFixing(euribor->fixingDate(settlementDate), 0.01, true);
		//SwapType
	VanillaSwap::Type swapType = VanillaSwap::Receiver;
		//FixedLeg
	SwapFixedLeg* fixed_Leg = new SwapFixedLeg(fixedRate, fixedLegDayCounter, fixedLegFrequency);
		//FloatingLeg
	SwapFloatingLeg* floating_leg = new SwapFloatingLeg(euribor, floatingLegDayCounter, floatingLegFrequency);

	VanillaSwap swap(swapType, nominal, fixed_Leg->fixedSchedule(settlementDate,maturity), fixed_Leg->getfixedRate(), fixed_Leg->getfixedLegDayCounter(),
		floating_leg->floatSchedule(settlementDate,maturity), floating_leg->getfloating_index(), 0.0, floating_leg->getfloatingLegDayCounter());

	boost::shared_ptr<PricingEngine> swapEngine(new DiscountingSwapEngine(discountingTermStructure));

	swap.setPricingEngine(swapEngine);
	return swap.NPV();
}


