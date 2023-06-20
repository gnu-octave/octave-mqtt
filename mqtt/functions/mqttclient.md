---
layout: "default"
permalink: "/functions/10_mqttclient/"
pkg_name: "mqtt"
pkg_version: "0.0.3"
pkg_description: "Basic Octave implementation of mqtt toolkit"
title: "Mqtt Toolkit - mqttclient"
category: "MQTT Functions"
func_name: "mqttclient"
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
<dt id="index-mqttclient"><span class="category">: </span><span><em><var>client</var> =</em> <strong>mqttclient</strong> <em>(<var>brokerAddr</var>)</em><a href='#index-mqttclient' class='copiable-anchor'></a></span></dt>
<dt id="index-mqttclient-1"><span class="category">: </span><span><em><var>client</var> =</em> <strong>mqttclient</strong> <em>(<var>brokerAddr</var>, [<var>name</var>, <var>value</var> ....])</em><a href='#index-mqttclient-1' class='copiable-anchor'></a></span></dt>
<dd><p>Create a MQTT client connection
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<dl compact="compact">
<dt><span><code>brokerAddr</code></span></dt>
<dd><p>name or ip address with protocol. ie: tcp://127.0.0.1.
 </p></dd>
<dt><span><code>name, value</code></span></dt>
<dd><p>Optional name / value pairs.
 </p></dd>
</dl>

<p>Known options are:
 </p><dl compact="compact">
<dt><span><code>Port</code></span></dt>
<dd><p>Numeric port number to connect to (default 1883)
 </p></dd>
<dt><span><code>Timeout</code></span></dt>
<dd><p>Numeric timeout value in seconds (default 5)
 </p></dd>
<dt><span><code>KeepAliveDuration</code></span></dt>
<dd><p>Numeric keep alive value in seconds (default 60)
 </p></dd>
<dt><span><code>ClientID</code></span></dt>
<dd><p>String client Id 
 </p></dd>
<dt><span><code>Username</code></span></dt>
<dd><p>String username
 </p></dd>
<dt><span><code>Password</code></span></dt>
<dd><p>String password
 </p></dd>
<dt><span><code>CARootCertificate</code></span></dt>
<dd><p>String full file path to a root certificate file when using a secure connection
 </p></dd>
<dt><span><code>ClientCertificate</code></span></dt>
<dd><p>String full file path to a client certificate file when using a secure connection
 </p></dd>
<dt><span><code>ClientKey</code></span></dt>
<dd><p>String full file path to a private client key file when using a secure connection
 </p></dd>
<dt><span><code>SSLPassword</code></span></dt>
<dd><p>String Password to decrypt the client key file
 </p></dd>
</dl>

<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<dl compact="compact">
<dt><span><code>client</code></span></dt>
<dd><p>a octave_mqtt object
 </p></dd>
</dl>

<span id="Properties"></span><h4 class="subsubheading">Properties</h4>
<p>A octave_mqtt object has the following properties:
 </p><dl compact="compact">
<dt><span><code>BrokerAddress</code></span></dt>
<dd><p>broker url
 </p></dd>
<dt><span><code>Port</code></span></dt>
<dd><p>Numeric port number to connect to (default 1883)
 </p></dd>
<dt><span><code>Timeout</code></span></dt>
<dd><p>Numeric timeout value in seconds (default 5)
 </p></dd>
<dt><span><code>KeepAliveDuration</code></span></dt>
<dd><p>Numeric keep alive value in seconds (default 60)
 </p></dd>
<dt><span><code>ClientID</code></span></dt>
<dd><p>String client Id 
 </p></dd>
</dl>

<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<p>Create a new mqttclient
 </p><div class="example">
<pre class="example"> <code>
 client = mqttclient(&quot;tcp://127.0.0.1);
 </code>
 </pre></div>

</dd></dl>