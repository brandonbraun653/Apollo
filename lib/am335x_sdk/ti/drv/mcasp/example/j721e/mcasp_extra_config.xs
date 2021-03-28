/* Create a heap for McASP test buffers */
var HeapMem = xdc.module('ti.sysbios.heaps.HeapMem');

var heapMemParams     = new HeapMem.Params;
heapMemParams.size    = 200000;
Program.global.myHeap = HeapMem.create(heapMemParams);

if (Program.build.target.name == "A53F")
{
    /* Speed up system tick due to lack of granularity in Task_sleep API
     * causing timeouts with faster A72 execution
     */
    var Clock = xdc.module('ti.sysbios.knl.Clock');
    Clock.tickPeriod = 10;
}

/* Create static task to match other devices */
var Task = xdc.module('ti.sysbios.knl.Task');
var task0Params = new Task.Params();
task0Params.priority      = 5;
task0Params.stackSize     = 0x4000;
task0Params.instance.name = "Audio_echo_Task";

Program.global.task0 = Task.create("&Audio_echo_Task", task0Params);

