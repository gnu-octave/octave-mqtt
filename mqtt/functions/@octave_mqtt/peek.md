---
layout: "default"
permalink: "/functions/@octave_mqtt/17_octavemqttpeek/"
pkg_name: "mqtt"
pkg_version: "0.0.6"
pkg_description: "Octave implementation of the MQTT toolkit"
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
  subitems:
- id: "news"
  name: "News"
  url: "/news"
- id: "manual"
  name: "Manual"
  url: "/manual"
---
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-peek"><span class="category-def">: </span><span><code class="def-type"><var class="var">msg</var> =</code> <strong class="def-name">peek</strong> <code class="def-code-arguments">(<var class="var">obj</var>)</code><a class="copiable-link" href="#index-peek"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-peek-1"><span class="category-def">: </span><span><code class="def-type"><var class="var">msg</var> =</code> <strong class="def-name">peek</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>)</code><a class="copiable-link" href="#index-peek-1"></a></span></dt>
<dd><p>Return the most recent message without removing it from the message queue.
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<dl class="table">
<dt><code class="code">obj</code></dt>
<dd><p>A previously created octave_mqtt object
 </p></dd>
<dt><code class="code">topic</code></dt>
<dd><p>Topic value to match.
 </p></dd>
</dl>

<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<dl class="table">
<dt><code class="code">msg</code></dt>
<dd><p>The most recent message.
 </p></dd>
</dl>

<p>If no topic is specified, the last message from any topic will be returned, otherwise the last
 matching the input topic.
</p>
<h4 class="subsubheading" id="Examples"><span>Examples<a class="copiable-link" href="#Examples"></a></span></h4>
<div class="example">
<pre class="example-preformatted"> <code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 msg = peek(client);
 </code>
 </pre></div>

</dd></dl>