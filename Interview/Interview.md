# Interview

## Introduction

### Personal information 

Ok, First let me introduce myself.

My name is wanghao, you can call me Matthew, a young man who was born in May 1995(nineteen ninety five), and I come from a rural area near Xinyang, Henan, which is approximately 200 kilometers away from Hefei.

From June in 2014(twenty fourteen) to 2018(twenty eighteen), I studied Network Engineering at LiShui University, This field falls under the umbrella of computer science.

After graduating, I worked at Hangzhou ShenHao Technology Company Limited where I focus on C/C++ development for robotics. From July 2020 to October 2021 I served as a C++ developer at Kylin Software Company Limited, working on a productivity software called zhongbiaopuhua, which is based on the open-source library libreoffice. In November 2021, I joined Aptiv and participated in the development of intelligent cockpit modules, including Camera, Radar, and Tuner.

### Advantage and Disadvantage
1. I am extroverted, so my communication skills are quite good, I am more enthusiastic and cheerful, and I also like to learn some new things.
2. However, compared with my friends, I might be slightly less patient and attentive. Therefore, when handling tasks, I holds myself to the standard of double-checking. For important matters or those involving others, I also seek assistance from someone else to prevent any inadverent oversights that could impact others.

### What hobbies do you usually have ?
1. I swim a lot, as company helps us get a gym membership card, where I taught myself to swim last year.
2. I also like cycling very much, and cycling around the lake on a nice day is an incredibly pleasant experience.

<div style="page-break-after: always;"></div>

## Projects
### Robot Development in Hangzhou ShenHao Technology Company Limted
1. At Hangzhou ShenHao Technology Company Limted，I work on robot-related development using C/C++. Specifically, I develop backend programs to control robots under the Ubuntu operating system. 
2. When this program starts, it first read task and waypoint information from the databse. Then it controls the robot to move to specified positions and perform specific tasks, such as taking photos, measuring temperatures, and detecting gas leaks. The results of tasks are saved back to the database. Finally, the robot proceeds to the next task point until all tasks are completed, returning to its initial position for rechargin and awaiting the next automatic or manual activation.

### Office Software Development in Kylin Software Company
1. In Kylin Software Company, The projects that our department is reponsible for is an office software called Zhongbiaopuhua Office Software. This software is based on an open-source software called LibreOffice and has undergone secondary development. We are using C++11 to migrate the functionality from the old version to the new version currently under development.
2. As a develpoer working on text styles within documents, I am responsible for handing various aspects of text, such as underlining, color, and size.

### Intelligent cockpit Development in Aptiv
1. At Aptiv, I am reponsible for developing features related to the intelligent cabin, including Camera, Radio and Radio.
2. Our Mainboard runs two operating systems: Qnx and Android. When a user clicks the screen to make a function request, and this requst passed through Android's frameworks layer to the Hal layer, then using the cross-system communication protocol VIP, the request is transmitted to the corresponding service process in Qnx. 
3. In the QNX system, numerous service processes run, including Camera and Tuner. Request coming from Android are distributed to these service process for handling tasks such as reading/writing configuration parameters and invoking hardware devices. The results of these operations are returned along the calling path to the upper-level caller. Based on the outcome, different pages, icons or prompts are displayed on the user-interaction screen.
4. Radar is a sub-moudle of Camera. In the QNX system, I was responsible for developing the service processes for both of these modules. The Radar module includes features such as radar icon and display and reverse distance display, while the Camera module encompasses functionalities like 360-degree surround view and reversing imaging.
5. The Camera development work, or rather maintenance work, has been under my responsible for less than a year due to the departure of my colleague who was in charge of the Tuner. I have been handling the Tuner since then. The Tuner functionality is relatively straightward, so I am solely responsible for all aspects, including Android's Frameworks layer, HAL layer, and QNX-side service programs. Requests initiated by the radio application are processed through the Frameworks service process, then pass through the HAL layer service process, and finally are received by the QNX-side service process. Here, the program interacts with the TUner chip, which eventually send the received radio data to the Audio module for playback through the speakers.

### Introduce the most impressive difficulties encountered in the work and how to solve them
1. Last year, while developing a radio chip, I encountered a memorable challenge. The firmware of this chip had been modified by colleagues at headquarters. However, in a situation where the chip manufacturer did not provide support and the assistance from headquarters was limited, I needed to determine the necessary initialization steps for the chip after power-up. This included indetifying which parameters to initialize and their order. Unfortunately, none of my colleagues in China had relevant experiences, so I practically started researching this issue from scratch.
2. To address this problem, we consulted the user manual for the chip and my boss helped me locate the production code specific to this chip. We modified the code to align with the radio's design architecture. Additionally, we communicated with colleagues at headquarters to discuss the challenge we encountered and made various attempts based on their feedback. The entire process took approximately a month, with an average of at least ten hours per day spent on learning, communication, and testing. Ultimately we sucessfully completed the radio's development taks within the deadline.
3. This question left a deep impression on me. Not only did I learn new knowledge while solving this series of problems, but I also gained insights into how to handle issues in an entirely new domain.

<div style="page-break-after: always;"></div>

## Reasons for resignation

### The reason why I leave from my first job.
1. My first job was paid so little， about 5000, that I have no saving other than renting or eating. I need to switch to a higher job to make my life more secure.

### The reason why I came to Beijing
1. In the first 20 years of my life, I rarely had the opportunity to venture beyond my hometown and the city where I pursued my eduction. When I turned 24, I made a decision to explore Beijing. At that time, I still possessed ample enthusiasm to discover new experiences, witness unfamiliar landscapes and encounter people I had never met before.

### The reason why I leave from my second job.
1. At that time, my department manager was planning to develop a new product, a project for online document storage. He asked me to work on front-end development, but I was't interested in it. Nevertheless, I helped them complete the initial version adn then decided to resign.

### The reason why I leave from Beijing.
1. At this time, I chose to go to Beijing because I wanted to broaden my horizons, meet new friends in a slightly distant places, and see what the northern part of our country looks like. After a year of a half, I achieved my goal. Life in Beijing was very hectic, far from home, and there was no opportunity to settle there, so I decided to leave when the opportunity to change jobs arose.

### The reason why I came to Suzhou
1. I have a good friend at Aptiv, and he helped me with an internal refernal for my resume. Many people from my hometown also work in Suzhou, including my aunt and some of my middle school classmates. It's not too far from home, about a 3-hours high-speed train ride, and I can go back home during the three-day hoildays.

### The reason why do you want to change work this time?
1. The first reason is that I need to switch to a job closer to home so that I can spend as much time as possible with my grandparents, who are quite elderly. 
2. Secondly, Hefei is a city that is reasonably suitable for me to settle down in, it's close to home, and property prices are acceptable. 
3. Thirdly, Volkswagen is a great company, and if I can join Volkswagen, I won't have to change jobs, houses, or cities anymore. 
4. In fact, during my last job search, I already saw opportunities in Heifei, but at that time, I didn't find a suitable one.

### The reason why you choose Volkswagen.
1. First HeFei is a suitable city for me to settle down in, as I said before, it's close to home, and property prices are acceptable.
2. Second, I am very willing to work with excellent people, as one of the best automobile in the world, employees who can work in Volkswagen have at least some excellent aspects to learn from.
3. Finally, if I have the opportunity to join Volkswagen, I won't have to worry about changing jobs, houses, or cities anymore.

<div style="page-break-after: always;"></div>

## 介绍

### 个人信息

Ok，首先做个自我介绍

我叫王浩，你也可以叫我 Matthew，一个出生于1995年的男孩，我来自河南信阳的一个农村，非常接近合肥，大概只有 200 公里远。

2014 年 6 月到 2018 年，我在丽水大学学习网络工程，这是计算机科学的范畴。

毕业以后，我在杭州申昊科技有限责任公司工作，专注于 C/C++ 机器人开发。2020 年 7 月到 2021 年 10 月，我在麒麟软件有限公司担任 C++ 开发工程师，致力于一款名为 Zhongbiaopuhua 的办公软件的开发，它基于开源库 libreoffice 。2021 年 11 月，我加入 Aptiv，并参与智能座舱相关模块的开发，包括 Camera，Radar，和 Tuner。

### 优点和缺点
1. 我是一个偏外向的人，所以沟通技能还不错，为人比较热心和开朗，也比较喜欢接触一些新的知识。
2. 相较于我的朋友，我可能稍显不够耐心和细心。因此，在处理事务时，我会自我要求多检查两遍。对于重要的事情或涉及其他人的事务，我还会请其他人帮忙检查，以防我的粗心会影响到他人。

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
### 第一次离职的原因
1. 我的第一份工作的薪水非常低，除了租房和吃饭，我几乎没有存款。我需要转换到一份更高薪的工作，以确保我的生活更加稳定。

### 去北京的原因
1. 在我生命的前 20 年里，我很少有机会去除了家乡和我求学的城市，所以在我 24 岁的那年，我选择了去北京，因为那个时候我还有足够的热情去探索新事物，去看我未见过的风景和人物。

### 第二次离职的原因
1. 当时，我的部门经理计划开发一款新产品，一个用于在线存储文档的项目。他要求我从事前端开发的工作，但我对此并不感兴趣。尽管如此，我还是帮助他们完成了初版，之后选择离职了。

### 从北京离开的原因
1. 我当时选择去北京的原因就是想涨涨见识，去一个稍远的地方认识一些新的朋友，看看祖国的北方是什么样子。一年半后，我的目标也实现了。北京的生活非常匆忙，离家也很远，而且没有机会在那里定居，所以我选择乘着换工作的机会离开了北京

### 选择去苏州的原因
1. 我有个好朋友在 Aptiv，他帮我内推了简历。我老家有很多人都在苏州这边工作，包括我的舅妈，我初中的同学。离家也不是很远，坐高铁大概 3 个小时左右，三天的节假日都可以回去。

### 这次换工作的原因
1. 第一个原因是我需要换一个离家更近的工作以便于尽可能多的陪伴祖父母，他们年纪已经很大了。 
2. 第二，就是合肥是一个还算适合我定居的城市，离家够近，房价还能接受。
3. 第三，大众是一个很好的公司，如果我能加入大众应该就不用在换工作，换房子，换城市了。
4. 实际上,上次找工作的时候已经看到合肥的机会了，但那个时候没有找到合适的机会。

### 选择大众的原因
1. 首先，合肥是一个很适合我定居的城市，就像我以前说的，离家够近，房价也能接受。
2. 再次，我很愿意和优秀的人一起工作。作为全球最好的汽车公司之一，在大众工作的员工至少都有优秀的一面值得我学习。
3. 最后，如果能有幸加入大众，我就不用再因为换工作，换房子，换城市而焦虑了。