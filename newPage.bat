@ECHO OFF
set fileName=%1

SET dtStamp=%date:~-4%-%date:~4,2%-%date:~7,2%

(
echo ---
echo layout: post
echo title: "%1"
echo description: ""
echo category:
echo tags: []
echo ---
echo {%% include JB/setup %%}
) > ".\_posts\%dtStamp%-%fileName%.md"