---
layout: page
title: Senior 1 Blog
tagline: Tracking the progress of our project
---
{% include JB/setup %}

#The Project
Read the [Project Guidelines](http://ecen4013.okstate.edu/docs/project2/fa2015/Fall2015Blacksmith2.0Requirements.pdf)

##About:

Insert information about the project here!

##The Team

###Lead Engineer
Nathan Lea

###Project Manager
Brian French

###Team Members

Matt Lichfield

Dante Xiang

Michael Pfitzner

####Post List

<ul class="posts">
  {% for post in site.posts %}
    <li><span>{{ post.date | date_to_string }}</span> &raquo; <a href="{{ BASE_PATH }}{{ post.url }}">{{ post.title }}</a></li>
  {% endfor %}
</ul>
