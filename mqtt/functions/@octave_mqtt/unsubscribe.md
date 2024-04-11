---
layout: "default"
permalink: "/functions/@octave_mqtt/24_octavemqttunsubscribe/"
pkg_name: "mqtt"
pkg_version: "0.0.5"
pkg_description: "Octave implementation of the MQTT toolkit"
title: "Mqtt Toolkit - @octave_mqtt/unsubscribe"
category: "MQTT Functions"
func_name: "@octave_mqtt/unsubscribe"
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
<dt class="deftypefn" id="index-unsubscribe"><span class="category-def">: </span><span><strong class="def-name">unsubscribe</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>)</code><a class="copiable-link" href='#index-unsubscribe'></a></span></dt>
<dd><p>Unsubscribe from <var class="var">topic</var>
</p>
<h4 class="subsubheading" id="Inputs">Inputs</h4>
<dl class="table">
<dt><code class="code">obj</code></dt>
<dd><p>A previously created octave_mqtt object
 </p></dd>
<dt><code class="code">topic</code></dt>
<dd><p>string topic name.
 </p></dd>
</dl>

<h4 class="subsubheading" id="Outputs">Outputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples">Examples</h4>
<div class="example">
<pre class="example-preformatted"> <code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 subscribe(client, &quot;test1&quot;);
 unsubscribe(client, &quot;test1&quot;);
 </code>
 </pre></div>


<p><strong class="strong">See also:</strong> mqttclient, subscribe.
 </p></dd></dl>