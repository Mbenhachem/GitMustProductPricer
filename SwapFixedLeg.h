
#include <ql/instruments/swap.hpp>
#include <ql/time/daycounter.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/time/schedule.hpp>



using namespace QuantLib;



class SwapFixedLeg
{
public:
	SwapFixedLeg(double FixedRate, DayCounter FixedLegDayCounter, Frequency FixedLegFrequency);

	void setfixedRate(double fixedRate);
	void setfixedLegDayCounter(DayCounter fixedLegDayCounter);
	void setfixedLegFrequency(Frequency fixedLegFrequency);
	double getfixedRate() const;
	DayCounter getfixedLegDayCounter() const;
	Frequency getfixedLegFrequency() const;

	Schedule fixedSchedule(Date settlementDate, Date maturity) const;
private:
	double fixedRate;
	DayCounter fixedLegDayCounter;
	Frequency fixedLegFrequency;

};
