---
layout: "default"
permalink: "/functions/@octave_mqtt/18_octavemqttwrite/"
pkg_name: "mqtt"
pkg_version: "0.0.6"
pkg_description: "Octave implementation of the MQTT toolkit"
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
  subitems:
- id: "news"
  name: "News"
  url: "/news"
- id: "manual"
  name: "Manual"
  url: "/manual"
---
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-write"><span class="category-def">: </span><span><strong class="def-name">write</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>, <var class="var">value</var>)</code><a class="copiable-link" href="#index-write"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-write-1"><span class="category-def">: </span><span><strong class="def-name">write</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>, <var class="var">value</var>, [<var class="var">propname</var>, <var class="var">propvalue</var> ....])</code><a class="copiable-link" href="#index-write-1"></a></span></dt>
<dd><p>Write <var class="var">value</var> to <var class="var">topic</var>.
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<dl class="table">
<dt><code class="code">obj</code></dt>
<dd><p>A previously created octave_mqtt object
 </p></dd>
<dt><code class="code">topic</code></dt>
<dd><p>String topic to write to.
 </p></dd>
<dt><code class="code">value</code></dt>
<dd><p>String value to write to topic.
 </p></dd>
<dt><code class="code">propname, propvalue</code></dt>
<dd><p>Optional property name / value pairs.
 </p></dd>
</dl>

<p>Known property options are:
 </p><dl class="table">
<dt><code class="code">QualityOfService</code></dt>
<dd><p>Numeric QualityOfService [0-2] (default 0)
 </p></dd>
<dt><code class="code">Retain</code></dt>
<dd><p>Boolean flag value for retaining message (default false)
 </p></dd>
</dl>

<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<dl class="table">
<dt><code class="code">client</code></dt>
<dd><p>A octave_mqtt object.<br>
 </p></dd>
</dl>

<h4 class="subsubheading" id="Examples"><span>Examples<a class="copiable-link" href="#Examples"></a></span></h4>
<p>Open a client connection and write some values.
 </p><div class="example">
<pre class="example-preformatted"> <code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 write(client, &quot;mytopic&quot;, &quot;test1&quot;);
 write(client, &quot;mytopic&quot;, &quot;test1&quot;, &quot;QualityOfService&quot;, 1);
 </code>
 </pre></div>


<p><strong class="strong">See also:</strong> mqttclient.
 </p></dd></dl>