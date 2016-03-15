
#include <ql/instruments/swap.hpp>
#include <ql/time/daycounter.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include "SwapFixedLeg.h"

using namespace QuantLib;


SwapFixedLeg::SwapFixedLeg(double FixedRate, DayCounter FixedLegDayCounter, Frequency FixedLegFrequency)
:fixedRate(FixedRate), fixedLegDayCounter(FixedLegDayCounter), fixedLegFrequency(FixedLegFrequency)
{
}

void SwapFixedLeg::setfixedRate(double fixedRate)
{
	this->fixedRate = fixedRate;
}

void SwapFixedLeg::setfixedLegDayCounter(DayCounter fixedLegDayCounter)
{
	this->fixedLegDayCounter = fixedLegDayCounter;
}

double SwapFixedLeg::getfixedRate() const
{
	return this->fixedRate;
}

DayCounter SwapFixedLeg::getfixedLegDayCounter() const
{
	return this->fixedLegDayCounter;
}

Frequency SwapFixedLeg::getfixedLegFrequency() const
{
	return this->fixedLegFrequency;
}

void SwapFixedLeg::setfixedLegFrequency(Frequency fixedLegFrequency)
{
	this->fixedLegFrequency;
}

Schedule SwapFixedLeg::fixedSchedule(Date settlementDate, Date maturity) const
{
	return Schedule(settlementDate, maturity, Period(fixedLegFrequency),
		TARGET(), ModifiedFollowing, ModifiedFollowing,
		DateGeneration::Forward, false);
}