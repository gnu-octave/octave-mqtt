---
layout: "default"
permalink: "/functions/@octave_mqtt/22_octavemqttsubscribe/"
pkg_name: "mqtt"
pkg_version: "0.0.3"
pkg_description: "Basic Octave implementation of mqtt toolkit"
title: "Mqtt Toolkit - @octave_mqtt/subscribe"
category: "MQTT Functions"
func_name: "@octave_mqtt/subscribe"
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
<dt id="index-subscribe"><span class="category">: </span><span><em><var>subs</var> =</em> <strong>subscribe</strong> <em>(<var>obj</var>, <var>topic</var>)</em><a href='#index-subscribe' class='copiable-anchor'></a></span></dt>
<dt id="index-subscribe-1"><span class="category">: </span><span><em><var>subs</var> =</em> <strong>subscribe</strong> <em>(<var>obj</var>, <var>topic</var>, [<var>propname</var>, <var>propvalue</var> ....])</em><a href='#index-subscribe-1' class='copiable-anchor'></a></span></dt>
<dd><p>Subscribe to a topic
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<dl compact="compact">
<dt><span><code>obj</code></span></dt>
<dd><p>A previously created octave_mqtt object
 </p></dd>
<dt><span><code>topic</code></span></dt>
<dd><p>String topic to subscribe to.
 </p></dd>
<dt><span><code>propname, propvalue</code></span></dt>
<dd><p>Optional property name / value pairs.
 </p></dd>
</dl>

<p>Known property name / value pairs:
 </p><dl compact="compact">
<dt><span><code>QualityOfService</code></span></dt>
<dd><p>Numeric QualityOfService [0-2] (default 0)
 </p></dd>
<dt><span><code>Callback</code></span></dt>
<dd><p>Callback function name or handle (default &quot;&quot;)
</p>
<p>The callback if provided will be passed the topic name and value.
 </p></dd>
</dl>

<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<dl compact="compact">
<dt><span><code>subs</code></span></dt>
<dd><p>a list of current subscriptions for this client.
 </p></dd>
</dl>

<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> <code>
 client = mqttclient(&quot;tcp://127.0.0.1);
 subs = subscribe(client, &quot;Test&quot;);
 </code>
 </pre></div>


<p><strong>See also:</strong> mqttclient, unsubscribe.
 </p></dd></dl>