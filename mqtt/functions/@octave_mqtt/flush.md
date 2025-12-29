---
layout: "default"
permalink: "/functions/@octave_mqtt/18_octavemqttflush/"
pkg_name: "mqtt"
pkg_version: "0.0.6"
pkg_description: "Octave implementation of the MQTT toolkit"
title: "Mqtt Toolkit - @octave_mqtt/flush"
category: "MQTT Functions"
func_name: "@octave_mqtt/flush"
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
<dt class="deftypefn def-line" id="index-flush"><span class="category-def">: </span><span><strong class="def-name">flush</strong> <code class="def-code-arguments">(<var class="var">obj</var>)</code><a class="copiable-link" href="#index-flush"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-flush-1"><span class="category-def">: </span><span><strong class="def-name">flush</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>)</code><a class="copiable-link" href="#index-flush-1"></a></span></dt>
<dd><p>Flush a MQTT client connection
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<dl class="table">
<dt><code class="code">obj</code></dt>
<dd><p>A previously created octave_mqtt object
 </p></dd>
<dt><code class="code">topic</code></dt>
<dd><p>Optional topic to clear from queue.
 </p></dd>
</dl>

<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples"><span>Examples<a class="copiable-link" href="#Examples"></a></span></h4>
<p>Open a client and flush the input
 </p><div class="example">
<pre class="example-preformatted"> <code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 flush(client);
 </code>
 </pre></div>

<p>Open a client and flush the input of only &rsquo;test&rsquo; topics
 </p><div class="example">
<pre class="example-preformatted"> <code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 flush(client, &quot;test&quot;);
 </code>
 </pre></div>


<p><strong class="strong">See also:</strong> mqttclient.
 </p></dd></dl>