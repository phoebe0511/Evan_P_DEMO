#ifndef PRODUCTDATA_H
#define PRODUCTDATA_H
#include <qstring.h>

class ProductData
{
public:
    QString price;
    QString product_name;
    QString product_id;
    QString Total_price;
    QString Quantity;
    enum Item1 {"12" , "Belt" ,"00A01" };



    ProductData();
};


public class ProductData {




    public enum product_detail
    {
        Item1 ("12" , "Belt" ,	"00A01" ) ,
        Item2 ("20" , "Jacket" ,"00A02" ) ,
        Item3 ("9" , "Shoes" ,	"00A03" ) ,
        Item4 ("12" , "Sweater" ,"00A04" ) ,
        Item5 ("36" , "Jeans" ,	"00A05" ) ,
        Item6 ("39" , "Skirt" ,	"00A06" ) ,
        Item7 ("38" , "Sweatshirt" ,"00A07" ) ,
        Item8 ("28" , "Pajamas" ,"00A08" ) ,
        Item9 ("28" , "Slacks" ,"00A09" ) ,
        Item10 ("33" , "T-shirt" ,"00A10" ) ,
        Item11 ("27" , "Taincoat" ,"00A11" ) ,
        Item12 ("25" , "Socks" ,"00A12" ) ;

        private final String out_price;
        private final String out_name;
        private final String out_num;


        private product_detail(String price ,String name,String num ) {
            out_price = price;
            out_name = name;
            out_num =num;

        }

        public String to_price(){
            return out_price;
        }
        public String to_name()
        {
            return out_name ;
        }
        public String to_id()
        {
            return  out_num;
        }

    }
}

#endif // PRODUCTDATA_H
