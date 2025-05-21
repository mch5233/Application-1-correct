# Application-1-correct
Mya Camacho-Hill
5142879
Link to Wokwi: https://wokwi.com/projects/431534312632120321
I did use AI for my code. I commented in my actual code where it was used and what it was used for. I mainly used it to come up with an idea of what I should print to represent the thermatic I chose. As well as give me a general idea of what should be filled into the blanks of the code given. 

For my code I chose the Healthcare thermatics. For my code I used the LED to indicate a heartbeat sort of like an EKG system. Then I used the message to indicate vitals along with the time stamp they were taken. 

Vary Priorities: Change the print task’s priority to 2 (higher than blink’s 1). With such short tasks and delays, you may not notice a big difference, but in principle the print task would preempt the blink task if it were ready. Given both tasks spend most time sleeping, the effect is minimal. In later projects with CPU-bound tasks, priority will matter more. Does anything happen to the LED if you increase the delay within the print task? What if you increase the number of characters printed?
When I change the prioriy of the vitals task to a 2 initially I did not notice a difference. Since it was printing quickly in my terminal it was hard to notice a difference. When i increased the delay time within the print task the LED still continued to blink following its print task as well as indicating that in my serial monitor. Even when I extend the number of characters it still continues to follow the 250 ms delay. 

Increase Load: Remove the vTaskDelay in the print task (making it a tight loop printing continuously). Be careful – this will flood the console. But it illustrates a point: if one task never yields, it can starve the other. In this case, the LED might stop blinking on schedule because the print task hogs the CPU. This is a starvation scenario, leading into Project 2. If you try this, reset it back after observing a few lines, to avoid crashing your serial output.
Yes after removing the delay the LED did stop printing and it was not able to print the indicator for the LED due to the flood from the print task. 

Thematic Customization: If you chose the space context, perhaps change the printed message to “Telemetry OK” or similar. In healthcare, print a pseudo heart rate. In security, print sensor status.  Assume you were a developer of one of these applications - might there be some considerations that you would want to take into consideration in how verbose (or not) you want your messages to be? Additionally, explain why this system benefits from having correct functionality at predictable times.
In my code I customized my message to print out simulated heart rate and SpO2 level along with the timestamp. I would say how verbose a message is as a developer is something to take into consideration because it may be too much for a log system or operator when in a medical enviorment. Simplfying the system to log important data or alerts will help to not flood logs with unimportant information so the important information is not missed. Predictable times are beneficial to having correct functionality because in a healthcare systems task must be timily. For example with the heartbeat LED, it must be in sync with the patients heartbeat because it can mislead healthcare workers to think something is wrong due to missed beats. For the vitals it must be consistent for logging purposes. 

Real-Time Concept Check:

Identify the period of each task; you can try to do this via the simulator, or perhaps by printing data to the console?:
LED blink task period: 500 ms two cycles each period that take 250 ms (on/off)

Print task period: 10000 ms of 10 seconds 

Because we used vTaskDelay, these periods are maintained fairly accurately. In a hard real-time requirement, missing a period (e.g., LED not toggling on time) might be a system failure.
Did our system tasks meet the timing requirements?
Yes 
How do you know?
I oberseved the LED blinking at what I believe to be 250 ms and the print task occured every 10 sec showing the timestamp when it did. 
How did you verify it?
I used the LED on/off indicator to count how many times it occured before the print task happened and it added up to 10000 ms. I used a timer to see if the LED was blinking on time and it was. 
If the LED task had been written in a single-loop with the print (see baseline super-loop code), you might have seen the LED timing disturbed by printing (especially if printing took variable time).

Did you try running the code?
Yes
Can you cause the LED to miss it's timing requirements?
Yes
If yes, how?
After running the code I saw that the LED only toggled after the print task occured indicating that it was missing its timing requirement and seemed to be utilizing the print tasks timing requirement due to the longprint() blocking the main function from running. Inside longprint() it has a delay of 10000 ms and this delay can be seen in the printed timestamp in the serial monitor. Here's an example of the timestamp it was giving:
Status: system running	leg toggle	 time=10500 ms
Status: system running	leg toggle	 time=20750 ms
Status: system running	leg toggle	 time=31000 ms
If no, what did you try?
By using multitasking, we achieved timing determinism for the blink.
