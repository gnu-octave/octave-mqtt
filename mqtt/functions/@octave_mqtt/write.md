---
layout: "default"
permalink: "/functions/@octave_mqtt/18_octavemqttwrite/"
pkg_name: "mqtt"
pkg_version: "0.0.3"
pkg_description: "Basic Octave implementation of mqtt toolkit"
title: "Mqtt Toolkit - @octave_mqtt/write"
category: "MQTT Functions"
func_name: "@octave_mqtt/write"
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
<dt id="index-write"><span class="category">: </span><span><em></em> <strong>write</strong> <em>(<var>obj</var>, <var>topic</var>, <var>value</var>)</em><a href='#index-write' class='copiable-anchor'></a></span></dt>
<dt id="index-write-1"><span class="category">: </span><span><em></em> <strong>write</strong> <em>(<var>obj</var>, <var>topic</var>, <var>value</var>, [<var>propname</var>, <var>propvalue</var> ....])</em><a href='#index-write-1' class='copiable-anchor'></a></span></dt>
<dd><p>Write <var>value</var> to <var>topic</var>.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<dl compact="compact">
<dt><span><code>obj</code></span></dt>
<dd><p>A previously created octave_mqtt object
 </p></dd>
<dt><span><code>topic</code></span></dt>
<dd><p>String topic to write to.
 </p></dd>
<dt><span><code>value</code></span></dt>
<dd><p>String value to write to topic.
 </p></dd>
<dt><span><code>propname, propvalue</code></span></dt>
<dd><p>Optional property name / value pairs.
 </p></dd>
</dl>

<p>Known property options are:
 </p><dl compact="compact">
<dt><span><code>QualityOfService</code></span></dt>
<dd><p>Numeric QualityOfService [0-2] (default 0)
 </p></dd>
<dt><span><code>Retain</code></span></dt>
<dd><p>boolean flag value for retaining message (default false)
 </p></dd>
</dl>

<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<dl compact="compact">
<dt><span><code>client</code></span></dt>
<dd><p>a octave_mqtt object.<br>
 </p></dd>
</dl>

<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<p>Open a client connection and write some values.
 </p><div class="example">
<pre class="example"> <code>
 client = mqttclient(&quot;tcp://127.0.0.1);
 write(client, &quot;mytopic&quot;, &quot;test1&quot;);
 write(client, &quot;mytopic&quot;, &quot;test1&quot;, &quot;QualityOfService&quot;, 1);
 </code>
 </pre></div>


<p><strong>See also:</strong> mqttclient.
 </p></dd></dl>