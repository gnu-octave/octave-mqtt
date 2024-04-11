---
layout: "default"
permalink: "/functions/@octave_mqtt/22_octavemqttsubscribe/"
pkg_name: "mqtt"
pkg_version: "0.0.5"
pkg_description: "Octave implementation of the MQTT toolkit"
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
<dl class="first-deftypefn">
<dt class="deftypefn" id="index-subscribe"><span class="category-def">: </span><span><code class="def-type"><var class="var">subs</var> =</code> <strong class="def-name">subscribe</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>)</code><a class="copiable-link" href='#index-subscribe'></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-subscribe-1"><span class="category-def">: </span><span><code class="def-type"><var class="var">subs</var> =</code> <strong class="def-name">subscribe</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>, [<var class="var">propname</var>, <var class="var">propvalue</var> ....])</code><a class="copiable-link" href='#index-subscribe-1'></a></span></dt>
<dd><p>Subscribe to a topic
</p>
<h4 class="subsubheading" id="Inputs">Inputs</h4>
<dl class="table">
<dt><code class="code">obj</code></dt>
<dd><p>A previously created octave_mqtt object
 </p></dd>
<dt><code class="code">topic</code></dt>
<dd><p>String topic to subscribe to.
 </p></dd>
<dt><code class="code">propname, propvalue</code></dt>
<dd><p>Optional property name / value pairs.
 </p></dd>
</dl>

<p>Known property name / value pairs:
 </p><dl class="table">
<dt><code class="code">QualityOfService</code></dt>
<dd><p>Numeric QualityOfService [0-2] (default 0)
 </p></dd>
<dt><code class="code">Callback</code></dt>
<dd><p>Callback function name or handle (default &quot;&quot;)
</p>
<p>If provided, the callback will be called with the topic name and 
 message as arguments.
 </p></dd>
</dl>

<h4 class="subsubheading" id="Outputs">Outputs</h4>
<dl class="table">
<dt><code class="code">subs</code></dt>
<dd><p>a list of current subscriptions for this client.
 </p></dd>
</dl>

<h4 class="subsubheading" id="Examples">Examples</h4>
<p>Subscribe to topic &rsquo;Test&rsquo;:
 </p><div class="example">
<pre class="example-preformatted"> <code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 subs = subscribe(client, &quot;Test&quot;);
 </code>
 </pre></div>

<p>Subscribe to topic &rsquo;Test&rsquo; and display any changed via callback:
 </p><div class="example">
<pre class="example-preformatted"> <code class="code">
 # define simple function to show callback data
 function showmessage(t,v), printf(&quot;Topic: %s Message: %s\n&quot;, t, v); endfunction

 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 subs = subscribe(client, &quot;Test&quot;, &quot;Callback&quot;, @showmessage);
 </code>
 </pre></div>


<p><strong class="strong">See also:</strong> mqttclient, unsubscribe.
 </p></dd></dl>