#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
typedef enum
{
    Production
    StubCode
}testEnvironment_e;
        

int networkAlertStub(float celcius,testEnvironment_e environment) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(Production == environment)
    {
        /* if celisus is less or equal to 200 return ok (200), else return notok(500)*/
        if( celcius <= 200)
        {
            return 200;
        }
        else
        {
            return 500;
        }
    }
    else
    {
        /* in case of Stubcode environment always return 200*/
        return 200;
    }
}

float computeCelciusValueFromFarenheit(float farenheit)
{
    float celcius = (farenheit - 32) * 5 / 9;
    
    return celcius;
}

void alertInCelcius(float farenheit,testEnvironment_e environment) {
    float celcius = computeCelciusValueFromFarenheit(farenheit);
    int returnCode = networkAlertStub(celcius,environment);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(303.6,StubCode);
    assert( alertFailureCount == 0);
    alertInCelcius(303.6,Production);
    assert( alertFailureCount == 0);
    alertInCelcius(400.5,StubCode);
    assert( alertFailureCount == 0);
    alertInCelcius(400.5,Production);
    assert( alertFailureCount == 1);
    
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
