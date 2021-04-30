#include <avr/io.h>
#include "ACTIVITY_1.h"
#include "ACTIVITY_2.h"
#include "ACTIVITY_3.h"
#include "ACTIVITY_3.h"

/** \brief main function where code execution
 *
 * \param void
 * \return int
 *
 */

int main(void)
{
    while(1)
    {
    firstact();
    secondact();
    thirdact();
    finalact();
    }
return 0;
}
