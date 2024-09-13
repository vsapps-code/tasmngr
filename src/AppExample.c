#include <stdio.h>
#include <assert.h>

#include "VSAPPS_globals.h"
#include "RBUFFER.h"

#define TEST_RBUFFER_SIZE   10

int main()
{
    RBuffer ringbuffer;
    unsigned int myRingbufferArray[TEST_RBUFFER_SIZE];

    unsigned int out_read = 0;
    unsigned int in_write = 0;
    bool result = 0;

    rbuffer_init(&ringbuffer, (void*)myRingbufferArray, sizeof(myRingbufferArray[0]), TEST_RBUFFER_SIZE);

    result = rbuffer_pop_one_elem(&ringbuffer, (void*)&out_read);
    assert(result == false);

    in_write = 5;
    result = rbuffer_push_one_elem(&ringbuffer, (void*)&in_write);
    assert(result == true);

    in_write = 7;
    result = rbuffer_push_one_elem(&ringbuffer, (void*)&in_write);
    assert(result == true);

    result = rbuffer_pop_one_elem(&ringbuffer, (void*)&out_read);
    assert(result == true);
    printf("%d\n", (int)out_read);
    assert(out_read == 5);

    result = rbuffer_pop_one_elem(&ringbuffer, (void*)&out_read);
    assert(result == true);
    assert(out_read == 7);

    out_read = 0;
    result = rbuffer_pop_one_elem(&ringbuffer, (void*)&out_read);
    assert(result == false);
    assert(out_read == 0);

    return 0;

}