#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

namespace cpp_primer { namespace chapter7 {
    class SaleData
    {
        public:
            SaleData() = default;
            SaleData(const std::string &s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) {}
            SaleData(const std::string &s):
                bookNo(s) {}
            SaleData(std::istream& );

            std::string isbn() const {
                return bookNo;
            }

            SaleData &combine(const SaleData&);

            double avg_price() const {
                return units_sold? revenue/units_sold : 0;
            }

        protected:
        private:

            std::string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
    };
}}

#endif // SALES_DATA_H
