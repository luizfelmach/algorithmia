if (b > 0 && a > INFLL -b)  //a+b vai dar overflow
if (b < 0 && a < -INFLL -b) //a+b vai dar underflow
if (b < 0 && a > INFLL+b)   //a-b vai dar overflow
if (b > 0 && a < -INFLL+b)  //a-b vai dar underflow
if (b > INFLL/a)            //a*b vai dar overflow
if (b < -INFLL/a)           //a*b vai dar underflow