# Application-1-correct
Mya Camacho-Hill
5142879
For my code I chose the Healthcare thermatics. For my code I used the LED to indicate a heartbeat sort of like an EKG system. Then I used the message to indicate vitals along with the time stamp they were taken. 
Vary Priorities: Change the print task’s priority to 2 (higher than blink’s 1). With such short tasks and delays, you may not notice a big difference, but in principle the print task would preempt the blink task if it were ready. Given both tasks spend most time sleeping, the effect is minimal. In later projects with CPU-bound tasks, priority will matter more. Does anything happen to the LED if you increase the delay within the print task? What if you increase the number of characters printed?
When I change the prioriy of the vitals task to a 2 initially I did not notice a difference. Since it was printing quickly in my terminal it was hard to notice a difference. When i increased the delay time within the print task the LED still continued to blink following its print task as well as indicating that in my serial monitor. Even when I extend the number of characters it still continues to follow the 250 ms delay. 

Increase Load: Remove the vTaskDelay in the print task (making it a tight loop printing continuously). Be careful – this will flood the console. But it illustrates a point: if one task never yields, it can starve the other. In this case, the LED might stop blinking on schedule because the print task hogs the CPU. This is a starvation scenario, leading into Project 2. If you try this, reset it back after observing a few lines, to avoid crashing your serial output.

Thematic Customization: If you chose the space context, perhaps change the printed message to “Telemetry OK” or similar. In healthcare, print a pseudo heart rate. In security, print sensor status.  Assume you were a developer of one of these applications - might there be some considerations that you would want to take into consideration in how verbose (or not) you want your messages to be? Additionally, explain why this system benefits from having correct functionality at predictable times.

Real-Time Concept Check:

Identify the period of each task; you can try to do this via the simulator, or perhaps by printing data to the console?:
LED blink task period:

Print task period:

Because we used vTaskDelay, these periods are maintained fairly accurately. In a hard real-time requirement, missing a period (e.g., LED not toggling on time) might be a system failure.

Did our system tasks meet the timing requirements?

How do you know?

How did you verify it?

If the LED task had been written in a single-loop with the print (see baseline super-loop code), you might have seen the LED timing disturbed by printing (especially if printing took variable time).

Did you try running the code?
Can you cause the LED to miss it's timing requirements?
If yes, how?
If no, what did you try?
By using multitasking, we achieved timing determinism for the blink.
