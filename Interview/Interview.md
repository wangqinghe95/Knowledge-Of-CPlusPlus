# Interview

## Introduction

### Personal information 

Ok, First let me introduce myself.

My name is wanghao, you can call me Matthew, a young man who was born in May 1995(nineteen ninety five), and I come from a rural area of Xinyang, Henan, which is approximately 200 kilometers away from Hefei.

From June in 2014(twenty fourteen) to 2018(twenty eighteen), I studied Network Engineering at LiShui University, This field falls under the umbrella of computer science.

After graduation, I worked at Hangzhou ShenHao Technology Company Limited where I focus on C/C++ development for robotics. From July 2020 to October 2021 I served as a C++ developer at Kylin Software Company Limited, working on a productivity software called zhongbiaopuhua office software, which is based on the open-source library libreoffice. In November 2021, I joined Aptiv and participated in the development of intelligent cockpit modules, including Camera, Radar, and Tuner.

### Advantage and Disadvantage
1. I am extroverted and enthusiastic, so my communication skills are quite good. I also like learning some new things and writing records and summary articles.
2. Sometimes, because I am too enthusiastic, I will not do my own things very well. So in the last two years, I have tried to limit my enthusiasm to a certain range, such as things related to myself.

### What hobbies do you usually have ?
1. I swim a lot, as company helps us get a gym membership card, where I taught myself to swim last year.
2. I also like cycling very much, and cycling around the lake on a nice day is an incredibly pleasant experience.

<div style="page-break-after: always;"></div>

## Projects

### Intelligent cockpit Development in Aptiv
1. At Aptiv, I am reponsible for developing features related to the intelligent cabin, including Camera, Radar and Radio.
2. Our Mainboard runs two operating systems: Qnx and Android. When a user clicks the screen to make a function request, and this requst passed through Android's frameworks layer to the Hal layer, then using the cross-system communication protocol VIP, the request is transmitted to the corresponding service process in Qnx. 
3. In the QNX system, numerous service processes run, including Camera and Tuner. Request coming from Android are distributed to these service process for handling tasks such as reading/writing configuration parameters and invoking hardware devices. The results of these operations are returned along the calling path to the upper-level caller. Based on the outcome, different pages, icons or prompts are displayed on the user-interaction screen.
4. Radar is a sub-moudle of Camera. In the QNX system, I was responsible for developing the service processes for both of these modules. The Radar module includes features such as radar icon and display and reverse distance display, while the Camera module encompasses functionalities like 360-degree surround view and reversing imaging.
5. The Camera development work, or rather maintenance work, has been under my responsible for less than a year due to the departure of my colleague who was in charge of the Tuner. I have been handling the Tuner since then. The Tuner functionality is relatively straightward, so I am solely responsible for all aspects, including Android's Frameworks layer, HAL layer, and QNX-side service programs. Requests initiated by the radio application are processed through the Frameworks service process, then pass through the HAL layer service process, and finally are received by the QNX-side service process. Here, the program interacts with the TUner chip, which eventually send the received radio data to the Audio module for playback through the speakers.

### Robot Development in Hangzhou ShenHao Technology Company Limted
1. At Hangzhou ShenHao Technology Company Limted，I work on robot-related development using C/C++. Specifically, I develop backend programs to control robots under the Ubuntu operating system. 
2. When this program starts, it first read task and waypoint information from the databse. Then it controls the robot to move to specified positions and perform specific tasks, such as taking photos, measuring temperatures, and detecting gas leaks. The results of tasks are saved back to the database. Finally, the robot proceeds to the next task point until all tasks are completed, returning to its initial position for rechargin and awaiting the next automatic or manual activation.

### Office Software Development in Kylin Software Company
1. In Kylin Software Company, The projects that our department is reponsible for is an office software called Zhongbiaopuhua Office Software. This software is based on an open-source software called LibreOffice and has undergone secondary development. We are using C++11 to migrate the functionality from the old version to the new version currently under development.
2. As a develpoer working on text styles within documents, I am responsible for handing various aspects of text, such as underlining, color, and size.

### Introduce the most impressive difficulties encountered in the work and how to solve them
1. Last year, while developing a radio chip, I encountered a memorable challenge. The firmware of this chip had been modified by colleagues at headquarters. However, in a situation where the chip manufacturer did not provide support and the assistance from headquarters was limited, I needed to determine the necessary initialization steps for the chip after power-up. This included indetifying which parameters to initialize and their order. Unfortunately, none of my colleagues in China had relevant experiences, so I practically started researching this issue from scratch.
2. To address this problem, we consulted the user manual for the chip and my boss helped me locate the production code specific to this chip. We modified the code to align with the radio's design architecture. Additionally, we communicated with colleagues at headquarters to discuss the challenge we encountered and made various attempts based on their feedback. The entire process took approximately a month, with an average of at least ten hours per day spent on learning, communication, and testing. Ultimately we sucessfully completed the radio's development taks within the deadline.
3. This question left a deep impression on me. Not only did I learn new knowledge while solving this series of problems, but I also gained insights into how to handle issues in an entirely new domain.

<div style="page-break-after: always;"></div>

## Reasons for resignation

### Reasons for the first two departures
1. The first time I left was because the salary was too low to support myself at that time. So I need to change a job.
2. The second time I left was just because the department leader wanted me to do front-end work, such as web development. I was not very interested in it, so I negotiated to leave.

### Why did you change so many city jobs
1. At every stage in one's life, there are different things one should do, of course, it's just suggested, not must. For me for instance, when I was 24 years, I came to Beijing to see the world more, because I have great enthuisasm to explore this world. and when I turned 27, I need to make plan for my future career, so I went back to Suzhou and joined Aptiv, because softwre development in the automobile industry is good direction for me and Suzhou is not far away my home, about 600 kilmeters, which means 3 hours of high-speed rail. 

### The reason for this job change
1. Now, nearly 30 years old, I should consider to balance the weight my family and work. My grandparents are enoug old and I want to spend more time with my grandparents. So VolkWagen in Heifei is a better opportuniry for me, first it will take me 2 hours to back to home if I have car. Second, as one of the best companies in the world, VolkWagen have more good chances and excellent employees. I am very willing to work with great people because I can be better by learning from my colleagues.

## What is your career plan
1. In the manufacturing industry, especially the automobile industry, software development is my deep direction, because it is very fulfilling to see that my code can run on the road.

## Others
1. I was preparing for my postgraduate exam
2. Suzhou is quite suitable for me, But VolkWagen in HeFei is better opportunity for me, not only because of VolkWagen is good, but also it is close to my hometown.