# 60-days-c-challengee

#include <stdio.h>
int main()
float basic_salary;
float hra_percent, da_percent,tax_percent;
float hra, da, tax, gross_salary;
printf("Enter the basic salary of the employee:\n");
scanf("%f",&basic_salary);
printf("Enter the hra percent:\n");
scanf("%f",&hra_percent);
printf("Enter the da percent: \n");
scanf("%f",&da_percent);
printf("Enter the tax percent:\n");
scanf("%f",&tax_percent);
hra =  basic_salary* (hra_percent/100);
printf("hra = %f\n",hra); 
da =  basic_salary* (da_percent/100);
printf("da = %f\n",da);
tax = basic_salary *(tax_percent/100);
printf("tax = %f\n", tax);
gross salary = basic_salary+hra+da-tax;
printf("gross salary = %f\n", gross_salary);
printf("Is gross salary> 50000?%d\n", gross_salary > 50000);
return 0;
}
