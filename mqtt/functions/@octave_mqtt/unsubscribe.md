---
layout: "default"
permalink: "/functions/@octave_mqtt/24_octavemqttunsubscribe/"
pkg_name: "mqtt"
pkg_version: "0.0.3"
pkg_description: "Basic Octave implementation of mqtt toolkit"
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
<dl class="def">
<dt id="index-unsubscribe"><span class="category">: </span><span><em></em> <strong>unsubscribe</strong> <em>(<var>obj</var>, <var>topic</var>)</em><a href='#index-unsubscribe' class='copiable-anchor'></a></span></dt>
<dd><p>Unsubscribe from <var>topic</var>
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<dl compact="compact">
<dt><span><code>obj</code></span></dt>
<dd><p>A previously created octave_mqtt object
 </p></dd>
<dt><span><code>topic</code></span></dt>
<dd><p>string topic name.
 </p></dd>
</dl>

<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> <code>
 client = mqttclient(&quot;tcp://127.0.0.1);
 subscribe(client, &quot;test1&quot;);
 unsubscribe(client, &quot;test1&quot;);
 </code>
 </pre></div>


<p><strong>See also:</strong> mqttclient, subscribe.
 </p></dd></dl>