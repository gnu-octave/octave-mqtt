---
layout: "default"
permalink: "/functions/@octave_mqtt/17_octavemqttpeek/"
pkg_name: "mqtt"
pkg_version: "0.0.3"
pkg_description: "Basic Octave implementation of mqtt toolkit"
title: "Mqtt Toolkit - @octave_mqtt/peek"
category: "MQTT Functions"
func_name: "@octave_mqtt/peek"
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
<dl class="def">
<dt id="index-peek"><span class="category">: </span><span><em><var>msg</var> =</em> <strong>peek</strong> <em>(<var>obj</var>)</em><a href='#index-peek' class='copiable-anchor'></a></span></dt>
<dt id="index-peek-1"><span class="category">: </span><span><em><var>msg</var> =</em> <strong>peek</strong> <em>(<var>obj</var>, <var>topic</var>)</em><a href='#index-peek-1' class='copiable-anchor'></a></span></dt>
<dd><p>Return the most recent message without removing it from the message queue.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<dl compact="compact">
<dt><span><code>obj</code></span></dt>
<dd><p>A previously created octave_mqtt object
 </p></dd>
<dt><span><code>topic</code></span></dt>
<dd><p>topic to match.
 </p></dd>
</dl>

<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<dl compact="compact">
<dt><span><code>msg</code></span></dt>
<dd><p>The most recent message.
 </p></dd>
</dl>

<p>If no topic is specified, the last message from any topic will be returned, otherwise the last
 matching the input topic.
</p>
<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> <code>
 client = mqttclient(&quot;tcp://127.0.0.1);
 msg = peek(client);
 </code>
 </pre></div>

</dd></dl>