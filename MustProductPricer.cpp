#include <ql/quantlib.hpp>
#include "MustProduct.h"

using namespace std;
using namespace QuantLib;
using namespace boost;

int main()
{
	//MarketData
	vector<Date> dates;
	vector<DiscountFactor> discountFactor;

	Date valuationDate(31, December, 2012);
	Settings::instance().evaluationDate() = valuationDate;

	dates.push_back(valuationDate); discountFactor.push_back(1.0);
	dates.push_back(Date(31, December, 2013));  discountFactor.push_back(0.99);
	dates.push_back(Date(31, December, 2024));  discountFactor.push_back(0.80);
	boost::shared_ptr<YieldTermStructure> forwardCurve(new InterpolatedDiscountCurve<LogLinear>(dates, discountFactor, Actual360()));

	discountFactor.pop_back(); discountFactor.pop_back();

	discountFactor.push_back(0.999);
	discountFactor.push_back(0.89);

	boost::shared_ptr<YieldTermStructure> oisCurve(new InterpolatedDiscountCurve<LogLinear>(dates, discountFactor, Actual360()));

	Handle<YieldTermStructure> discountingTermStructure(oisCurve);
	Handle<YieldTermStructure> forwardingTermStructure(forwardCurve);
	Date previousResetDate(20, November, 2012);
	Date maturity(20, November, 2022);


	MustVanilleSwap* must_Swap = new MustVanilleSwap(100000, previousResetDate, maturity, Semiannual, Actual360(), 0.01, Actual360(), Quarterly);

	double res = must_Swap->Price(discountingTermStructure, forwardingTermStructure);


}