# Interview

## Introduction

### Personal information 

Ok, First let me introduce myself.

My name is wanghao, you can call me Matthew, a young man who was born in May 1995(nineteen ninety five), and I come from a rural area near Xinyang, Henan, which is approximately 200 kilometers away from Hefei.

From June in 2014(twenty fourteen) to 2018(twenty eighteen), I studied Network Engineering at LiShui University, This field falls under the umbrella of computer science.

After graduating, I worked at Hangzhou ShenHao Technology Company Limited where I focus on C/C++ development for robotics. From July 2020 to October 2021 I served as a C++ developer at Kylin Software Company Limited, working on a productivity software called zhongbiaopuhua, which is based on the open-source library libreoffice. In November 2021, I joined Aptiv and participated in the development of intelligent cockpit modules, including Camera, Radar, and Tuner.

### Advantage and Disadvantage
1. I am extroverted, so my communication skills are quite good. Besides, I am more enthusiastic and cheerful, and I also like learning some new things and writing records and summary articles.
2. Sometimes, because I am too enthusiastic, I will not do my own things very well. So, in the last two years, I have tried to limit my enthusiasm to a certain range, such as things related to myself.

### What hobbies do you usually have ?
1. I swim a lot, as company helps us get a gym membership card, where I taught myself to swim last year.
2. I also like cycling very much, and cycling around the lake on a nice day is an incredibly pleasant experience.

<div style="page-break-after: always;"></div>

## Projects

### Intelligent cockpit Development in Aptiv
1. At Aptiv, I am reponsible for developing features related to the intelligent cabin, including Camera, Radio and Radio.
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
1. At every stage in one's life, there are different things one should do, of course, it's just suggested, not must. For instance, when I was 24 years, I came to Beijing to see the world more, because I have great enthuisasm to explore this world. and when I turned 26, I need to plan to my career, so I went back to Suzhou and joined Aptiv, because it only takes about 3 hours to get home. 

### The reason for this job change
1. Now, nearly 30 years old, there is a better opportunity that help me balance the weight of my family and work, it's VolkWagen in Heifei. first you know, if I have a car, I can only spend 2 hours back to home to see my grandparents, and secondly, as one of the best companies in the world, VolkWagen have more good chances and excellent employees. I am very willing to work with excellent people.

## What is your career plan
1. In the manufacturing industry, especially the automobile industry, software development is my deep direction, because it is very fulfilling to see that my code can run on the road.

## Others
1. I was preparing for my postgraduate exam

<div style="page-break-after: always;"></div>

## 介绍

### 个人信息

Ok，首先做个自我介绍

我叫王浩，你也可以叫我 Matthew，一个出生于1995年的男孩，我来自河南信阳的一个农村，非常接近合肥，大概只有 200 公里远。

2014 年 6 月到 2018 年，我在丽水大学学习网络工程，这是计算机科学的范畴。

毕业以后，我在杭州申昊科技有限责任公司工作，专注于 C/C++ 机器人开发。2020 年 7 月到 2021 年 10 月，我在麒麟软件有限公司担任 C++ 开发工程师，致力于一款名为 Zhongbiaopuhua 的办公软件的开发，它基于开源库 libreoffice 。2021 年 11 月，我加入 Aptiv，并参与智能座舱相关模块的开发，包括 Camera，Radar，和 Tuner。

### 优点和缺点
1. 我是一个偏外向的人，所以沟通技能还不错，为人比较热心和开朗，也比较喜欢接触一些新的知识，写一些记录和总结的文章。
2. 有时候会因为太过热情会导致我自己的事情完成的不是很好，所以我最近两年都是尽量将热情限制在一定范围内，比如和自己相关的事情。

### 平时有什么兴趣爱好
1. 我经常游泳，因为公司帮助我们办理健身房的会员卡，去年在那里我自学了游泳
2. 我也非常喜欢骑行，天气好的时候绕湖骑行是一件是非常惬意的事情

<div style="page-break-after: always;"></div>

## 项目介绍

### 机器人开发
1. 在申昊科技有限公司，我使用 C/C++ 做一些机器人相关的开发工作，具体来说，就是在Ubuntu 系统下开发控制机器人的后台程序
2. 当这个后台程序启动时，会先从数据库中读取任务和点位的信息。然后，它会控制机器人前往指定位置，并执行一些特定的任务，例如拍照、测温、检测是否有气体泄漏等。任务的结果会保存到数据库中。最后，机器人会前往下一个任务点，直至所有任务完成后，返回到初始位置充电，等待下一次自动或手动唤醒

### 办公软件的开发
1. 在麒麟软件公司，我们部门的产品是一款办公软件，叫做zhongbiaopuhua办公软件。这个软件是基于一款叫做liboffice开源软件做的二次开发，我们使用 C++11 将旧版本的功能迁移到正在开发的新版本中。
2. 作为文档中文本样式的开发人员，我负责处理文本的各种外观特性，例如划线、颜色和大小

### 智能座舱开发
1. 在Aptiv，我负责开发智能座舱的相关功能，包括相机、雷达和收音机。
2. 我们的主板上运行着两个操作系统，分别是Qnx和Android。当用户点击屏幕发出功能请求时，这个请求会经过 Android 的 frameworks 层传递到 Hal 层，然后通过跨系统通信协议 VIP 将该请求传递到 Qnx 中对应的服务进程。
3. 在 QNX 系统中，有许多服务进程在运行，包括 Camera 和Tuner 等。来自 Android 的请求会被分发到各个服务进程中进行处理，例如读写配置参数、调用硬件设备等。处理的结果会按照调用路径返回给上层调用者，并根据调用结果在与用户交互的屏幕上显示不同的页面、图标或提示信息。
4. Radar 是 Camera 的子模块。在 QNX 系统中，我负责开发这两个模块的服务进程。Radar 模块涉及雷达图标显示、倒车距离显示等功能，而 Camera 模块则包括 360 环视和倒车影像等功能。
5. Camera 开发工作，或者说是维护工作，不到一年时间，因为负责 Tuner 的同事的离职，我接手了 Tuner 直到现在。Tuner 功能比较简单，所以所有内容都由我一个人负责，包括 Android 的 Frameworks 层，Hal 层以及 QNX 侧的服务程序。收音机应用程序发起的请求到 Frameworks 服务进程，再经过 Hal 层的服务进程，最后被 QNX 侧的服务进程接收，并且在这里程序操作 Tuner 芯片，最后芯片会将接收到的电台数据发送给 Audio 模块，通过喇叭播放出电台声音。

### 介绍一下你工作中遇到的印象最深刻的问题以及如何解决它们的
1. 去年，我在开发一款收音机芯片时遇到了一个令人印象深刻的问题。这款芯片的固件内容曾由总部的同事修改过。然而，在芯片厂商不提供支持且总部同事的支持有限的情况下，我需要确定芯片上电后应该执行哪些初始化操作，包括初始化步骤、参数和顺序等。遗憾的是，国内同事中没有人有相关经验，因此我几乎是从零开始研究这个问题
2. 为了解决这个问题，我们查找了这款芯片的量产代码，并对其进行了修改，以适配当前的收音机设计架构。我们还与总部同事沟通，讨论了遇到的问题，并根据他们的意见进行了各种尝试。整个过程持续了大约一个月，每天平均至少十个小时的学习、沟通和测试。最终，在截至日期前，我们成功完成了收音机的目标开发任务。
3. 这个问题我印象很深刻，不仅是因为在解决这一系列的问题过程中学习到的新知识，而且知道了如何去处理全新领域中的问题

<div style="page-break-after: always;"></div>

## 离职原因
### 前两次离职原因
1. 第一次离职是因为当时的薪资太低了，扣除租房和吃饭的花销后，工作一年之后的我几乎没有任何积蓄。所以只能换一份能够让我生活更稳定的工作。
2. 第二次离职单纯的因为当时部门领导想让我去做前端工作，比如 web 网页开发，我对此并不是很兴趣，所以就协商离职了。

### 为什么会换这么多城市
1. 我始终认为一个人在人生的每个阶段都有每个阶段应该去做的事。比如 在 24 岁就应该多去看看世界，在 27 岁可以考虑自己的未来的职业规划，30 岁的时候，需要多为亲人计划一下，父母，未来的伴侣，甚至是孩子。所以我 24 岁的时候带着极大的热情去了北京扩展眼界，26 岁的时候来到苏州规划职业生涯，而现在将近 30 岁的时候，想要平衡一下家里老人和工作的权重，意思是我想多花点时间陪陪祖父母，如果我选择在合肥工作，只需要2小时我就能回到家。

### 这次换工作的原因
1. 我想要尽可能的多陪陪老家的祖父母，所以想去合肥。
2. 大众是作为全球最优秀的汽车公司之一，当然是许多人想进的公司，包括我。

## 职业规划？
1. 在制造业，特别是汽车行业，做软件开发是我的深耕方向，因为能看到自己写的代码能跑在路上是一件非常有成就感的事情。

## 其他
1. 那时我正在准备研究生考试