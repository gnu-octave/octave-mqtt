---
layout: "default"
permalink: "/functions/@octave_mqtt/17_octavemqttread/"
pkg_name: "mqtt"
pkg_version: "0.0.5"
pkg_description: "Octave implementation of the MQTT toolkit"
title: "Mqtt Toolkit - @octave_mqtt/read"
category: "MQTT Functions"
func_name: "@octave_mqtt/read"
navigation:
- id: "overview"
  name: "Overview"
  url: "/index"
- id: "Functions"
  name: "Function Reference"
  url: "/functions"
- id: "14_MQTTFunctions"
  name: "&nbsp;&nbsp;MQTT Functions"
  url: "/functions/#14_MQTTFunctions"
- id: "news"
  name: "News"
  url: "/news"
- id: "manual"
  name: "Manual"
  url: "/manual"
---
<dl class="first-deftypefn">
<dt class="deftypefn" id="index-read"><span class="category-def">: </span><span><code class="def-type"><var class="var">msgs</var> =</code> <strong class="def-name">read</strong> <code class="def-code-arguments">(<var class="var">obj</var>)</code><a class="copiable-link" href='#index-read'></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-read-1"><span class="category-def">: </span><span><code class="def-type"><var class="var">msgs</var> =</code> <strong class="def-name">read</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>)</code><a class="copiable-link" href='#index-read-1'></a></span></dt>
<dd><p>Read available messages and remove from message queue. 
</p>
<h4 class="subsubheading" id="Inputs">Inputs</h4>
<dl class="table">
<dt><code class="code">obj</code></dt>
<dd><p>A previously created octave_mqtt object
 </p></dd>
<dt><code class="code">topic</code></dt>
<dd><p>Topic to match.
 </p></dd>
</dl>

<h4 class="subsubheading" id="Outputs">Outputs</h4>
<dl class="table">
<dt><code class="code">msgs</code></dt>
<dd><p>Messages from the message queue
 </p></dd>
</dl>

<p>If no topic is specified, messages from any topic will be returned, otherwise from the
 matching input topic.
</p>
<h4 class="subsubheading" id="Examples">Examples</h4>
<div class="example">
<pre class="example-preformatted"> <code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 msgs = read(client, &quot;test&quot;);
 </code>
 </pre></div>

</dd></dl>