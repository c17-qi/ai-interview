import re
content = open('index.html', encoding='utf-8').read()
new_input = '''<section class=\
input-wrapper\>
        <textarea id=\userInput\ placeholder=\说点什么...
回车发送\></textarea>
        <div class=\bottom-row\>
          <div class=\btn-group\>
            <button class=\icon-btn\ id=\sttBtn\ title=\语音输入\>
              <svg viewBox=\0
0
24
24\ fill=\none\ stroke=\currentColor\ stroke-width=\2\ stroke-linecap=\round\ stroke-linejoin=\round\ width=\20\ height=\20\>
                <path d=\M12
2a3
3
0
0
0-3
3v7a3
3
0
0
0
6
0V5a3
3
0
0
0-3-3Z\></path>
                <path d=\M19
10v2a7
7
0
0
1-14
0v-2\></path>
                <line x1=\12\ x2=\12\ y1=\19\ y2=\22\></line>
              </svg>
            </button>
            <button class=\icon-btn\ id=\muteBtn\ title=\静音\>
              <svg viewBox=\0
0
24
24\ fill=\none\ stroke=\currentColor\ stroke-width=\2\ stroke-linecap=\round\ stroke-linejoin=\round\ width=\20\ height=\20\>
                <polygon points=\11
5
6
9
2
9
2
15
6
15
11
19
11
5\></polygon>
                <path d=\M19.07
4.93a10
10
0
0
1
0
14.14M15.54
8.46a5
5
0
0
1
0
7.07\></path>
              </svg>
            </button>
            <button class=\icon-btn\ id=\micBtn\ title=\开启语音通话\>
              <svg viewBox=\0
0
24
24\ fill=\none\ stroke=\currentColor\ stroke-width=\2\ stroke-linecap=\round\ stroke-linejoin=\round\ width=\20\ height=\20\>
                <path d=\M22
16.92v3a2
2
0
0
1-2.18
2
19.79
19.79
0
0
1-8.63-3.07
19.5
19.5
0
0
1-6-6
19.79
19.79
0
0
1-3.07-8.67A2
2
0
0
1
4.11
2h3a2
2
0
0
1
2
1.72
12.84
12.84
0
0
0
.7
2.81
2
2
0
0
1-.45
2.11L8.09
9.91a16
16
0
0
0
6
6l1.27-1.27a2
2
0
0
1
2.11-.45
12.84
12.84
0
0
0
2.81.7A2
2
0
0
1
22
16.92z\></path>
              </svg>
            </button>
          </div>
          <div class=\send-controls\>
            <button id=\sendBtn\>发送</button>
          </div>
        </div>
        <div class=\status-row\>
          <span class=\status\ id=\statusLabel\>空闲</span>
        </div>
      </section>'''
old_pattern = r'<section class=\input-wrapper\>.*?</section>'
new_content = re.sub(old_pattern, new_input, content, flags=re.DOTALL)
open('index.html', 'w', encoding='utf-8').write(new_content)

