
#include <ql/instruments/swap.hpp>
#include <ql/time/daycounter.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/time/schedule.hpp>



using namespace QuantLib;



class SwapFloatingLeg
{
public:
	SwapFloatingLeg(boost::shared_ptr<IborIndex> floating_index, DayCounter floatingLegDayCounter, Frequency floatingLegFrequency);

	void setfloating_index(boost::shared_ptr<IborIndex> floating_index);
	void setfloatingLegDayCounter(DayCounter floatingLegDayCounter);
	void setfloatingLegFrequency(Frequency floatingLegFrequency);
	boost::shared_ptr<IborIndex> getfloating_index() const;
	DayCounter getfloatingLegDayCounter() const;
	Frequency getfloatingLegFrequency() const;

	Schedule floatSchedule(Date settlementDate, Date maturity) const;
private:
	boost::shared_ptr<IborIndex> floating_index;
	DayCounter floatingLegDayCounter;
	Frequency floatingLegFrequency;

};
