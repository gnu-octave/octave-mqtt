---
layout: "default"
permalink: "/manual/"
title: "Mqtt Toolkit - Manual"
pkg_name: "mqtt"
version: "0.0.5"
description: "Octave implementation of the MQTT toolkit"
navigation:
- id: "overview"
  name: "Overview"
  url: "/index"
- id: "Functions"
  name: "Function Reference"
  url: "/functions"
- id: "news"
  name: "News"
  url: "/news"
- id: "manual"
  name: "Manual"
- id: "Installing-and-loading-1"
  name: "&nbsp;&nbsp; Installing and loading"
  url: "/manual/#Installing-and-loading-1"
- id: "Basic-Usage-Overview-1"
  name: "&nbsp;&nbsp; Basic Usage Overview"
  url: "/manual/#Basic-Usage-Overview-1"
- id: "Function-Reference-1"
  name: "&nbsp;&nbsp; Function Reference"
  url: "/manual/#Function-Reference-1"
---
<div class="top-level-extent" id="Top">
<div class="nav-panel">
<p>
Next: <a href="#Installing-and-loading" accesskey="n" rel="next">Installing and loading</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<h1 class="top" id="Introduction">Introduction</h1>
<p>The Octave MQTT toolkit is a set of MQTT routines for GNU Octave
</p>
<div class="element-contents" id="SEC_Contents">
<h2 class="contents-heading">Table of Contents</h2>
<div class="contents">
<ul class="toc-numbered-mark">
  <li><a id="toc-Installing-and-loading-1" href="#Installing-and-loading">1 Installing and loading</a>
  <ul class="toc-numbered-mark">
    <li><a id="toc-Online-Direct-install" href="#Online-Direct-install">1.1 Online Direct install</a></li>
    <li><a id="toc-Off_002dline-install" href="#Off_002dline-install">1.2 Off-line install</a></li>
    <li><a id="toc-Loading" href="#Loading">1.3 Loading</a></li>
  </ul></li>
  <li><a id="toc-Basic-Usage-Overview-1" href="#Basic-Usage-Overview">2 Basic Usage Overview</a>
  <ul class="toc-numbered-mark">
    <li><a id="toc-Connection-to-a-broker" href="#Connection-to-a-broker">2.1 Connection to a broker</a></li>
    <li><a id="toc-Subscribe-to-a-Topic" href="#Subscribe-to-a-Topic">2.2 Subscribe to a Topic</a></li>
    <li><a id="toc-Write-to-a-Topic" href="#Write-to-a-Topic">2.3 Write to a Topic</a></li>
    <li><a id="toc-Read-from-subscribed-Topics" href="#Read-from-subscribed-Topics">2.4 Read from subscribed Topics</a></li>
    <li><a id="toc-Close-the-client" href="#Close-the-client">2.5 Close the client</a></li>
  </ul></li>
  <li><a id="toc-Function-Reference-1" href="#Function-Reference">3 Function Reference</a>
  <ul class="toc-numbered-mark">
    <li><a id="toc-MQTT-Functions-1" href="#MQTT-Functions">3.1 MQTT Functions</a>
    <ul class="toc-numbered-mark">
      <li><a id="toc-_0040octave_005fmqtt_002fflush" href="#g_t_0040octave_005fmqtt_002fflush">3.1.1 @octave_mqtt/flush</a></li>
      <li><a id="toc-_0040octave_005fmqtt_002fpeek" href="#g_t_0040octave_005fmqtt_002fpeek">3.1.2 @octave_mqtt/peek</a></li>
      <li><a id="toc-_0040octave_005fmqtt_002fread" href="#g_t_0040octave_005fmqtt_002fread">3.1.3 @octave_mqtt/read</a></li>
      <li><a id="toc-_0040octave_005fmqtt_002fsubscribe" href="#g_t_0040octave_005fmqtt_002fsubscribe">3.1.4 @octave_mqtt/subscribe</a></li>
      <li><a id="toc-_0040octave_005fmqtt_002funsubscribe" href="#g_t_0040octave_005fmqtt_002funsubscribe">3.1.5 @octave_mqtt/unsubscribe</a></li>
      <li><a id="toc-_0040octave_005fmqtt_002fwrite" href="#g_t_0040octave_005fmqtt_002fwrite">3.1.6 @octave_mqtt/write</a></li>
      <li><a id="toc-mqttclient" href="#mqttclient">3.1.7 mqttclient</a></li>
    </ul></li>
  </ul></li>
  <li><a id="toc-GNU-General-Public-License" href="#Copying">Appendix A GNU General Public License</a></li>
  <li><a id="toc-Index-1" href="#Index" rel="index">Index</a></li>
</ul>
</div>
</div>
<hr>
<div class="chapter-level-extent" id="Installing-and-loading">
<div class="nav-panel">
<p>
Next: <a href="#Basic-Usage-Overview" accesskey="n" rel="next">Basic Usage Overview</a>, Previous: <a href="#Top" accesskey="p" rel="prev">Introduction</a>, Up: <a href="#Top" accesskey="u" rel="up">Introduction</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<h2 class="chapter" id="Installing-and-loading-1">1 Installing and loading</h2>
<a class="index-entry-id" id="index-Installing-and-loading"></a>
<p>The toolkit must be installed and then loaded to be used.
</p>
<p>It can be installed in <abbr class="acronym">GNU</abbr> Octave directly from the website,
or can be installed in an off-line mode via a downloaded tarball.
</p>
<p>The toolkit has a dependency on the PAHO-MQTT-C library (<a class="url" href="https://www.eclipse.org/paho/">https://www.eclipse.org/paho/</a>), so it must be installed in order
to successfully install the toolkit.
</p>
<p>The toolkit must be then be loaded once per each <abbr class="acronym">GNU</abbr> Octave session in order to use its functionality.
</p>
<ul class="mini-toc">
<li><a href="#Online-Direct-install" accesskey="1">Online Direct install</a></li>
<li><a href="#Off_002dline-install" accesskey="2">Off-line install</a></li>
<li><a href="#Loading" accesskey="3">Loading</a></li>
</ul>
<div class="section-level-extent" id="Online-Direct-install">
<h3 class="section">1.1 Online Direct install</h3>
<a class="index-entry-id" id="index-Online-install"></a>
<p>With an internet connection available, the octave mqtt package can be installed from
the octave-mqtt website using the following command within <abbr class="acronym">GNU</abbr> Octave:
</p>
<div class="example">
<pre class="example-preformatted">pkg install -forge mqtt
</pre></div>
<p>The latest released version of the toolkit will be downloaded and installed.
</p>
</div>
<div class="section-level-extent" id="Off_002dline-install">
<h3 class="section">1.2 Off-line install</h3>
<a class="index-entry-id" id="index-Off_002dline-install"></a>
<p>With the toolkit package already downloaded
(<a class="url" href="https://github.com/gnu-octave/octave-mqtt/releases/download/release-0.0.5/octave-mqtt-0.0.5.tar.gz">https://github.com/gnu-octave/octave-mqtt/releases/download/release-0.0.5/octave-mqtt-0.0.5.tar.gz</a>),
and in the current directory when running <abbr class="acronym">GNU</abbr> Octave, the package can be installed using the following command
within <abbr class="acronym">GNU</abbr> Octave:
</p>
<div class="example">
<pre class="example-preformatted">pkg install octave-mqtt-0.0.5.tar.gz
</pre></div>
</div>
<div class="section-level-extent" id="Loading">
<h3 class="section">1.3 Loading</h3>
<a class="index-entry-id" id="index-Loading"></a>
<p>Regardless of the method of installing the toolkit, in order to use its functions,
the toolkit must be loaded using the pkg load command:
</p>
<div class="example">
<pre class="example-preformatted">pkg load mqtt
</pre></div>
<p>The toolkit must be loaded on each <abbr class="acronym">GNU</abbr> Octave session.
</p>
<hr>
</div>
</div>
<div class="chapter-level-extent" id="Basic-Usage-Overview">
<div class="nav-panel">
<p>
Next: <a href="#Function-Reference" accesskey="n" rel="next">Function Reference</a>, Previous: <a href="#Installing-and-loading" accesskey="p" rel="prev">Installing and loading</a>, Up: <a href="#Top" accesskey="u" rel="up">Introduction</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<h2 class="chapter" id="Basic-Usage-Overview-1">2 Basic Usage Overview</h2>
<a class="index-entry-id" id="index-Basic-Usage-Overview"></a>
<p>The overview connects to the public broker at HiveMQ (<a class="url" href="https://www.hivemq.com/public-mqtt-broker/">https://www.hivemq.com/public-mqtt-broker/</a>)
and follows this general flow:
</p>
<ul class="mini-toc">
<li><a href="#Connection-to-a-broker" accesskey="1">Connection to a broker</a></li>
<li><a href="#Subscribe-to-a-Topic" accesskey="2">Subscribe to a Topic</a></li>
<li><a href="#Write-to-a-Topic" accesskey="3">Write to a Topic</a></li>
<li><a href="#Read-from-subscribed-Topics" accesskey="4">Read from subscribed Topics</a></li>
<li><a href="#Close-the-client" accesskey="5">Close the client</a></li>
</ul>
<div class="section-level-extent" id="Connection-to-a-broker">
<h3 class="section">2.1 Connection to a broker</h3>
<a class="index-entry-id" id="index-Connection-to-a-broker"></a>
<p>Connection to the broker is done using the mqttclient function.
</p>
<h4 class="subsubheading" id="Example">Example</h4>
<div class="example">
<pre class="example-preformatted"><code class="code">
brokerAddress = &quot;tcp://broker.hivemq.com&quot;;
port = 1883;
client = mqttclient(brokerAddress, &quot;Port&quot;, port)
</code>
<kbd class="kbd">
client =
  Client with properties
    BrokerAddress: tcp://broker.hivemq.com
             Port: 1883
         ClientID: 
          Timeout: 5
KeepAliveDuration: 60
    Subscriptions: [0x3] table
        Connected: 1
</kbd>
</pre></div>
<p>Additional properties can be included for Timeout, Username, Password and more.
</p>
</div>
<div class="section-level-extent" id="Subscribe-to-a-Topic">
<h3 class="section">2.2 Subscribe to a Topic</h3>
<a class="index-entry-id" id="index-Subscribe-to-a-Topic"></a>
<p>To get notifications for changes to a topic, subscribe to the topic.
</p>
<h4 class="subsubheading" id="Example-1">Example</h4>
<div class="example">
<pre class="example-preformatted"><code class="code">
topic = &quot;octave/test/field1&quot;;
subscribe(client, topic)
</code>
<kbd class="kbd">
ans =
  scalar structure containing the fields:
    Topic = octave/test/field1
    QualityOfService = 0
    Callback =
</kbd>
</pre></div>
</div>
<div class="section-level-extent" id="Write-to-a-Topic">
<h3 class="section">2.3 Write to a Topic</h3>
<a class="index-entry-id" id="index-Write-to-a-Topic"></a>
<p>To publish data to the broker, use the wrote function.
</p>
<h4 class="subsubheading" id="Example-2">Example</h4>
<div class="example">
<pre class="example-preformatted"><code class="code">
write(client, topic, &quot;hello world&quot;)
</code>
</pre></div>
</div>
<div class="section-level-extent" id="Read-from-subscribed-Topics">
<h3 class="section">2.4 Read from subscribed Topics</h3>
<a class="index-entry-id" id="index-Read-from-subscribed-Topics"></a>
<p>Reading data from a topic can be done using the peek function (which will not clear the data from the received queue)
or the read function (that will clear the message from the received queue)
</p>
<h4 class="subsubheading" id="Example-3">Example</h4>
<div class="example">
<pre class="example-preformatted"><code class="code">
# see if there is message
msg = peek(client)
</code>
<kbd class="kbd">
msg =
  scalar structure containing the fields:
    Time = 1.6560e+09
    Topic = octave/test/field1
    Data = hello world
</kbd>
<code class="code">
# read message from queue
msg = read(client)
</code>
<kbd class="kbd">
msg =
  scalar structure containing the fields:
    Time = 1.6560e+09
    Topic = octave/test/field1
    Data = hello world
</kbd>
</pre></div>
</div>
<div class="section-level-extent" id="Close-the-client">
<h3 class="section">2.5 Close the client</h3>
<a class="index-entry-id" id="index-Close-the-client"></a>
<p>To close the client and free any resources, use the clear function.
</p>
<h4 class="subsubheading" id="Example-4">Example</h4>
<div class="example">
<pre class="example-preformatted"><code class="code">
clear client
</code>
</pre></div>
<hr>
</div>
</div>
<div class="chapter-level-extent" id="Function-Reference">
<div class="nav-panel">
<p>
Next: <a href="#Copying" accesskey="n" rel="next">GNU General Public License</a>, Previous: <a href="#Basic-Usage-Overview" accesskey="p" rel="prev">Basic Usage Overview</a>, Up: <a href="#Top" accesskey="u" rel="up">Introduction</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<h2 class="chapter" id="Function-Reference-1">3 Function Reference</h2>
<a class="index-entry-id" id="index-Function-Reference"></a>
<p>The functions currently available in the toolkit are described below;
</p>
<ul class="mini-toc">
<li><a href="#MQTT-Functions" accesskey="1">MQTT Functions</a></li>
</ul>
<hr>
<div class="section-level-extent" id="MQTT-Functions">
<div class="nav-panel">
<p>
Up: <a href="#Function-Reference" accesskey="u" rel="up">Function Reference</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<h3 class="section" id="MQTT-Functions-1">3.1 MQTT Functions</h3>
<a class="index-entry-id" id="index-MQTT-Functions"></a>
<ul class="mini-toc">
<li><a href="#g_t_0040octave_005fmqtt_002fflush" accesskey="1">@octave_mqtt/flush</a></li>
<li><a href="#g_t_0040octave_005fmqtt_002fpeek" accesskey="2">@octave_mqtt/peek</a></li>
<li><a href="#g_t_0040octave_005fmqtt_002fread" accesskey="3">@octave_mqtt/read</a></li>
<li><a href="#g_t_0040octave_005fmqtt_002fsubscribe" accesskey="4">@octave_mqtt/subscribe</a></li>
<li><a href="#g_t_0040octave_005fmqtt_002funsubscribe" accesskey="5">@octave_mqtt/unsubscribe</a></li>
<li><a href="#g_t_0040octave_005fmqtt_002fwrite" accesskey="6">@octave_mqtt/write</a></li>
<li><a href="#mqttclient" accesskey="7">mqttclient</a></li>
</ul>
<div class="subsection-level-extent" id="g_t_0040octave_005fmqtt_002fflush">
<h4 class="subsection">3.1.1 @octave_mqtt/flush</h4>
<a class="index-entry-id" id="index-flush"></a>
<dl class="first-deftypefn">
<dt class="deftypefn" id="index-flush-1"><span class="category-def">: </span><span><strong class="def-name">flush</strong> <code class="def-code-arguments">(<var class="var">obj</var>)</code><a class="copiable-link" href='#index-flush-1'></a></span></dt>
<dd><p>Flush a MQTT client connection
</p>
<h4 class="subsubheading" id="Inputs">Inputs</h4>
<dl class="table">
<dt><code class="code">obj</code></dt>
<dd><p>A previously created octave_mqtt object
</p></dd>
</dl>
<h4 class="subsubheading" id="Outputs">Outputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples">Examples</h4>
<p>Open a client and flush the input
</p><div class="example">
<pre class="example-preformatted"><code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 flush(client);
 </code>
</pre></div>
<p><strong class="strong">See also:</strong> mqttclient.
</p></dd></dl>
</div>
<div class="subsection-level-extent" id="g_t_0040octave_005fmqtt_002fpeek">
<h4 class="subsection">3.1.2 @octave_mqtt/peek</h4>
<a class="index-entry-id" id="index-peek"></a>
<dl class="first-deftypefn">
<dt class="deftypefn" id="index-peek-1"><span class="category-def">: </span><span><code class="def-type"><var class="var">msg</var> =</code> <strong class="def-name">peek</strong> <code class="def-code-arguments">(<var class="var">obj</var>)</code><a class="copiable-link" href='#index-peek-1'></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-peek-2"><span class="category-def">: </span><span><code class="def-type"><var class="var">msg</var> =</code> <strong class="def-name">peek</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>)</code><a class="copiable-link" href='#index-peek-2'></a></span></dt>
<dd><p>Return the most recent message without removing it from the message queue.
</p>
<h4 class="subsubheading" id="Inputs-1">Inputs</h4>
<dl class="table">
<dt><code class="code">obj</code></dt>
<dd><p>A previously created octave_mqtt object
</p></dd>
<dt><code class="code">topic</code></dt>
<dd><p>Topic value to match.
</p></dd>
</dl>
<h4 class="subsubheading" id="Outputs-1">Outputs</h4>
<dl class="table">
<dt><code class="code">msg</code></dt>
<dd><p>The most recent message.
</p></dd>
</dl>
<p>If no topic is specified, the last message from any topic will be returned, otherwise the last
 matching the input topic.
</p>
<h4 class="subsubheading" id="Examples-1">Examples</h4>
<div class="example">
<pre class="example-preformatted"><code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 msg = peek(client);
 </code>
</pre></div>
</dd></dl>
</div>
<div class="subsection-level-extent" id="g_t_0040octave_005fmqtt_002fread">
<h4 class="subsection">3.1.3 @octave_mqtt/read</h4>
<a class="index-entry-id" id="index-read"></a>
<dl class="first-deftypefn">
<dt class="deftypefn" id="index-read-1"><span class="category-def">: </span><span><code class="def-type"><var class="var">msgs</var> =</code> <strong class="def-name">read</strong> <code class="def-code-arguments">(<var class="var">obj</var>)</code><a class="copiable-link" href='#index-read-1'></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-read-2"><span class="category-def">: </span><span><code class="def-type"><var class="var">msgs</var> =</code> <strong class="def-name">read</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>)</code><a class="copiable-link" href='#index-read-2'></a></span></dt>
<dd><p>Read available messages and remove from message queue.
</p>
<h4 class="subsubheading" id="Inputs-2">Inputs</h4>
<dl class="table">
<dt><code class="code">obj</code></dt>
<dd><p>A previously created octave_mqtt object
</p></dd>
<dt><code class="code">topic</code></dt>
<dd><p>Topic to match.
</p></dd>
</dl>
<h4 class="subsubheading" id="Outputs-2">Outputs</h4>
<dl class="table">
<dt><code class="code">msgs</code></dt>
<dd><p>Messages from the message queue
</p></dd>
</dl>
<p>If no topic is specified, messages from any topic will be returned, otherwise from the
 matching input topic.
</p>
<h4 class="subsubheading" id="Examples-2">Examples</h4>
<div class="example">
<pre class="example-preformatted"><code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 msgs = read(client, &quot;test&quot;);
 </code>
</pre></div>
</dd></dl>
</div>
<div class="subsection-level-extent" id="g_t_0040octave_005fmqtt_002fsubscribe">
<h4 class="subsection">3.1.4 @octave_mqtt/subscribe</h4>
<a class="index-entry-id" id="index-subscribe"></a>
<dl class="first-deftypefn">
<dt class="deftypefn" id="index-subscribe-1"><span class="category-def">: </span><span><code class="def-type"><var class="var">subs</var> =</code> <strong class="def-name">subscribe</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>)</code><a class="copiable-link" href='#index-subscribe-1'></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-subscribe-2"><span class="category-def">: </span><span><code class="def-type"><var class="var">subs</var> =</code> <strong class="def-name">subscribe</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>, [<var class="var">propname</var>, <var class="var">propvalue</var> ....])</code><a class="copiable-link" href='#index-subscribe-2'></a></span></dt>
<dd><p>Subscribe to a topic
</p>
<h4 class="subsubheading" id="Inputs-3">Inputs</h4>
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
<h4 class="subsubheading" id="Outputs-3">Outputs</h4>
<dl class="table">
<dt><code class="code">subs</code></dt>
<dd><p>a list of current subscriptions for this client.
</p></dd>
</dl>
<h4 class="subsubheading" id="Examples-3">Examples</h4>
<p>Subscribe to topic &rsquo;Test&rsquo;:
</p><div class="example">
<pre class="example-preformatted"><code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 subs = subscribe(client, &quot;Test&quot;);
 </code>
</pre></div>
<p>Subscribe to topic &rsquo;Test&rsquo; and display any changed via callback:
</p><div class="example">
<pre class="example-preformatted"><code class="code">
 # define simple function to show callback data
 function showmessage(t,v), printf(&quot;Topic: %s Message: %s\n&quot;, t, v); endfunction
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 subs = subscribe(client, &quot;Test&quot;, &quot;Callback&quot;, @showmessage);
 </code>
</pre></div>
<p><strong class="strong">See also:</strong> mqttclient, unsubscribe.
</p></dd></dl>
</div>
<div class="subsection-level-extent" id="g_t_0040octave_005fmqtt_002funsubscribe">
<h4 class="subsection">3.1.5 @octave_mqtt/unsubscribe</h4>
<a class="index-entry-id" id="index-unsubscribe"></a>
<dl class="first-deftypefn">
<dt class="deftypefn" id="index-unsubscribe-1"><span class="category-def">: </span><span><strong class="def-name">unsubscribe</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>)</code><a class="copiable-link" href='#index-unsubscribe-1'></a></span></dt>
<dd><p>Unsubscribe from <var class="var">topic</var>
</p>
<h4 class="subsubheading" id="Inputs-4">Inputs</h4>
<dl class="table">
<dt><code class="code">obj</code></dt>
<dd><p>A previously created octave_mqtt object
</p></dd>
<dt><code class="code">topic</code></dt>
<dd><p>string topic name.
</p></dd>
</dl>
<h4 class="subsubheading" id="Outputs-4">Outputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples-4">Examples</h4>
<div class="example">
<pre class="example-preformatted"><code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 subscribe(client, &quot;test1&quot;);
 unsubscribe(client, &quot;test1&quot;);
 </code>
</pre></div>
<p><strong class="strong">See also:</strong> mqttclient, subscribe.
</p></dd></dl>
</div>
<div class="subsection-level-extent" id="g_t_0040octave_005fmqtt_002fwrite">
<h4 class="subsection">3.1.6 @octave_mqtt/write</h4>
<a class="index-entry-id" id="index-write"></a>
<dl class="first-deftypefn">
<dt class="deftypefn" id="index-write-1"><span class="category-def">: </span><span><strong class="def-name">write</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>, <var class="var">value</var>)</code><a class="copiable-link" href='#index-write-1'></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-write-2"><span class="category-def">: </span><span><strong class="def-name">write</strong> <code class="def-code-arguments">(<var class="var">obj</var>, <var class="var">topic</var>, <var class="var">value</var>, [<var class="var">propname</var>, <var class="var">propvalue</var> ....])</code><a class="copiable-link" href='#index-write-2'></a></span></dt>
<dd><p>Write <var class="var">value</var> to <var class="var">topic</var>.
</p>
<h4 class="subsubheading" id="Inputs-5">Inputs</h4>
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
<h4 class="subsubheading" id="Outputs-5">Outputs</h4>
<dl class="table">
<dt><code class="code">client</code></dt>
<dd><p>A octave_mqtt object.<br>
</p></dd>
</dl>
<h4 class="subsubheading" id="Examples-5">Examples</h4>
<p>Open a client connection and write some values.
</p><div class="example">
<pre class="example-preformatted"><code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 write(client, &quot;mytopic&quot;, &quot;test1&quot;);
 write(client, &quot;mytopic&quot;, &quot;test1&quot;, &quot;QualityOfService&quot;, 1);
 </code>
</pre></div>
<p><strong class="strong">See also:</strong> mqttclient.
</p></dd></dl>
</div>
<div class="subsection-level-extent" id="mqttclient">
<h4 class="subsection">3.1.7 mqttclient</h4>
<a class="index-entry-id" id="index-mqttclient"></a>
<dl class="first-deftypefn">
<dt class="deftypefn" id="index-mqttclient-1"><span class="category-def">: </span><span><code class="def-type"><var class="var">client</var> =</code> <strong class="def-name">mqttclient</strong> <code class="def-code-arguments">(<var class="var">brokerAddr</var>)</code><a class="copiable-link" href='#index-mqttclient-1'></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-mqttclient-2"><span class="category-def">: </span><span><code class="def-type"><var class="var">client</var> =</code> <strong class="def-name">mqttclient</strong> <code class="def-code-arguments">(<var class="var">brokerAddr</var>, [<var class="var">name</var>, <var class="var">value</var> ....])</code><a class="copiable-link" href='#index-mqttclient-2'></a></span></dt>
<dd><p>Create a MQTT client connection
</p>
<h4 class="subsubheading" id="Inputs-6">Inputs</h4>
<dl class="table">
<dt><code class="code">brokerAddr</code></dt>
<dd><p>Name or IP address with protocol. ie: tcp://127.0.0.1.
</p></dd>
<dt><code class="code">name, value</code></dt>
<dd><p>Optional name / value pairs.
</p></dd>
</dl>
<p>Known options are:
</p><dl class="table">
<dt><code class="code">Port</code></dt>
<dd><p>Numeric port number to connect to (default 1883)
</p></dd>
<dt><code class="code">Timeout</code></dt>
<dd><p>Numeric timeout value in seconds (default 5)
</p></dd>
<dt><code class="code">KeepAliveDuration</code></dt>
<dd><p>Numeric keep alive value in seconds (default 60)
</p></dd>
<dt><code class="code">ClientID</code></dt>
<dd><p>String client Id
</p></dd>
<dt><code class="code">Username</code></dt>
<dd><p>String username
</p></dd>
<dt><code class="code">Password</code></dt>
<dd><p>String password
</p></dd>
<dt><code class="code">CARootCertificate</code></dt>
<dd><p>String full file path to a root certificate file when using a secure connection
</p></dd>
<dt><code class="code">ClientCertificate</code></dt>
<dd><p>String full file path to a client certificate file when using a secure connection
</p></dd>
<dt><code class="code">ClientKey</code></dt>
<dd><p>String full file path to a private client key file when using a secure connection
</p></dd>
<dt><code class="code">SSLPassword</code></dt>
<dd><p>String Password to decrypt the client key file
</p></dd>
</dl>
<h4 class="subsubheading" id="Outputs-6">Outputs</h4>
<dl class="table">
<dt><code class="code">client</code></dt>
<dd><p>a octave_mqtt object
</p></dd>
</dl>
<h4 class="subsubheading" id="Properties">Properties</h4>
<p>A octave_mqtt object has the following properties:
</p><dl class="table">
<dt><code class="code">BrokerAddress</code></dt>
<dd><p>Broker URL
</p></dd>
<dt><code class="code">Port</code></dt>
<dd><p>Numeric port number to connect to (default 1883)
</p></dd>
<dt><code class="code">Timeout</code></dt>
<dd><p>Numeric timeout value in seconds (default 5)
</p></dd>
<dt><code class="code">KeepAliveDuration</code></dt>
<dd><p>Numeric keep alive value in seconds (default 60)
</p></dd>
<dt><code class="code">ClientID</code></dt>
<dd><p>String client Id
</p></dd>
<dt><code class="code">Connected</code></dt>
<dd><p>logical 0|1 for connection status
</p></dd>
<dt><code class="code">Subscriptions</code></dt>
<dd><p>List of topics currently subscribed to
</p></dd>
</dl>
<h4 class="subsubheading" id="Examples-6">Examples</h4>
<p>Create a new mqttclient
</p><div class="example">
<pre class="example-preformatted"><code class="code">
 client = mqttclient(&quot;tcp://127.0.0.1&quot;);
 </code>
</pre></div>
</dd></dl>
<hr>
</div>
</div>
</div>
<div class="appendix-level-extent" id="Copying">
<div class="nav-panel">
<p>
Next: <a href="#Index" accesskey="n" rel="next">Index</a>, Previous: <a href="#Function-Reference" accesskey="p" rel="prev">Function Reference</a>, Up: <a href="#Top" accesskey="u" rel="up">Introduction</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<h2 class="appendix" id="GNU-General-Public-License">Appendix A GNU General Public License</h2>
<a class="index-entry-id" id="index-warranty"></a>
<a class="index-entry-id" id="index-copyright"></a>
<div class="center">Version 3, 29 June 2007
</div>
<div class="display">
<pre class="display-preformatted">Copyright &copy; 2007 Free Software Foundation, Inc. <a class="url" href="http://fsf.org/">http://fsf.org/</a>
Everyone is permitted to copy and distribute verbatim copies of this
license document, but changing it is not allowed.
</pre></div>
<h3 class="heading" id="Preamble">Preamble</h3>
<p>The GNU General Public License is a free, copyleft license for
software and other kinds of works.
</p>
<p>The licenses for most software and other practical works are designed
to take away your freedom to share and change the works.  By contrast,
the GNU General Public License is intended to guarantee your freedom
to share and change all versions of a program&mdash;to make sure it remains
free software for all its users.  We, the Free Software Foundation,
use the GNU General Public License for most of our software; it
applies also to any other work released this way by its authors.  You
can apply it to your programs, too.
</p>
<p>When we speak of free software, we are referring to freedom, not
price.  Our General Public Licenses are designed to make sure that you
have the freedom to distribute copies of free software (and charge for
them if you wish), that you receive source code or can get it if you
want it, that you can change the software or use pieces of it in new
free programs, and that you know you can do these things.
</p>
<p>To protect your rights, we need to prevent others from denying you
these rights or asking you to surrender the rights.  Therefore, you
have certain responsibilities if you distribute copies of the
software, or if you modify it: responsibilities to respect the freedom
of others.
</p>
<p>For example, if you distribute copies of such a program, whether
gratis or for a fee, you must pass on to the recipients the same
freedoms that you received.  You must make sure that they, too,
receive or can get the source code.  And you must show them these
terms so they know their rights.
</p>
<p>Developers that use the GNU GPL protect your rights with two steps:
(1) assert copyright on the software, and (2) offer you this License
giving you legal permission to copy, distribute and/or modify it.
</p>
<p>For the developers&rsquo; and authors&rsquo; protection, the GPL clearly explains
that there is no warranty for this free software.  For both users&rsquo; and
authors&rsquo; sake, the GPL requires that modified versions be marked as
changed, so that their problems will not be attributed erroneously to
authors of previous versions.
</p>
<p>Some devices are designed to deny users access to install or run
modified versions of the software inside them, although the
manufacturer can do so.  This is fundamentally incompatible with the
aim of protecting users&rsquo; freedom to change the software.  The
systematic pattern of such abuse occurs in the area of products for
individuals to use, which is precisely where it is most unacceptable.
Therefore, we have designed this version of the GPL to prohibit the
practice for those products.  If such problems arise substantially in
other domains, we stand ready to extend this provision to those
domains in future versions of the GPL, as needed to protect the
freedom of users.
</p>
<p>Finally, every program is threatened constantly by software patents.
States should not allow patents to restrict development and use of
software on general-purpose computers, but in those that do, we wish
to avoid the special danger that patents applied to a free program
could make it effectively proprietary.  To prevent this, the GPL
assures that patents cannot be used to render the program non-free.
</p>
<p>The precise terms and conditions for copying, distribution and
modification follow.
</p>
<h3 class="heading" id="TERMS-AND-CONDITIONS">TERMS AND CONDITIONS</h3>
<ol class="enumerate" start="0">
<li> Definitions.
<p>&ldquo;This License&rdquo; refers to version 3 of the GNU General Public License.
</p>
<p>&ldquo;Copyright&rdquo; also means copyright-like laws that apply to other kinds
of works, such as semiconductor masks.
</p>
<p>&ldquo;The Program&rdquo; refers to any copyrightable work licensed under this
License.  Each licensee is addressed as &ldquo;you&rdquo;.  &ldquo;Licensees&rdquo; and
&ldquo;recipients&rdquo; may be individuals or organizations.
</p>
<p>To &ldquo;modify&rdquo; a work means to copy from or adapt all or part of the work
in a fashion requiring copyright permission, other than the making of
an exact copy.  The resulting work is called a &ldquo;modified version&rdquo; of
the earlier work or a work &ldquo;based on&rdquo; the earlier work.
</p>
<p>A &ldquo;covered work&rdquo; means either the unmodified Program or a work based
on the Program.
</p>
<p>To &ldquo;propagate&rdquo; a work means to do anything with it that, without
permission, would make you directly or secondarily liable for
infringement under applicable copyright law, except executing it on a
computer or modifying a private copy.  Propagation includes copying,
distribution (with or without modification), making available to the
public, and in some countries other activities as well.
</p>
<p>To &ldquo;convey&rdquo; a work means any kind of propagation that enables other
parties to make or receive copies.  Mere interaction with a user
through a computer network, with no transfer of a copy, is not
conveying.
</p>
<p>An interactive user interface displays &ldquo;Appropriate Legal Notices&rdquo; to
the extent that it includes a convenient and prominently visible
feature that (1) displays an appropriate copyright notice, and (2)
tells the user that there is no warranty for the work (except to the
extent that warranties are provided), that licensees may convey the
work under this License, and how to view a copy of this License.  If
the interface presents a list of user commands or options, such as a
menu, a prominent item in the list meets this criterion.
</p>
</li><li> Source Code.
<p>The &ldquo;source code&rdquo; for a work means the preferred form of the work for
making modifications to it.  &ldquo;Object code&rdquo; means any non-source form
of a work.
</p>
<p>A &ldquo;Standard Interface&rdquo; means an interface that either is an official
standard defined by a recognized standards body, or, in the case of
interfaces specified for a particular programming language, one that
is widely used among developers working in that language.
</p>
<p>The &ldquo;System Libraries&rdquo; of an executable work include anything, other
than the work as a whole, that (a) is included in the normal form of
packaging a Major Component, but which is not part of that Major
Component, and (b) serves only to enable use of the work with that
Major Component, or to implement a Standard Interface for which an
implementation is available to the public in source code form.  A
&ldquo;Major Component&rdquo;, in this context, means a major essential component
(kernel, window system, and so on) of the specific operating system
(if any) on which the executable work runs, or a compiler used to
produce the work, or an object code interpreter used to run it.
</p>
<p>The &ldquo;Corresponding Source&rdquo; for a work in object code form means all
the source code needed to generate, install, and (for an executable
work) run the object code and to modify the work, including scripts to
control those activities.  However, it does not include the work&rsquo;s
System Libraries, or general-purpose tools or generally available free
programs which are used unmodified in performing those activities but
which are not part of the work.  For example, Corresponding Source
includes interface definition files associated with source files for
the work, and the source code for shared libraries and dynamically
linked subprograms that the work is specifically designed to require,
such as by intimate data communication or control flow between those
subprograms and other parts of the work.
</p>
<p>The Corresponding Source need not include anything that users can
regenerate automatically from other parts of the Corresponding Source.
</p>
<p>The Corresponding Source for a work in source code form is that same
work.
</p>
</li><li> Basic Permissions.
<p>All rights granted under this License are granted for the term of
copyright on the Program, and are irrevocable provided the stated
conditions are met.  This License explicitly affirms your unlimited
permission to run the unmodified Program.  The output from running a
covered work is covered by this License only if the output, given its
content, constitutes a covered work.  This License acknowledges your
rights of fair use or other equivalent, as provided by copyright law.
</p>
<p>You may make, run and propagate covered works that you do not convey,
without conditions so long as your license otherwise remains in force.
You may convey covered works to others for the sole purpose of having
them make modifications exclusively for you, or provide you with
facilities for running those works, provided that you comply with the
terms of this License in conveying all material for which you do not
control copyright.  Those thus making or running the covered works for
you must do so exclusively on your behalf, under your direction and
control, on terms that prohibit them from making any copies of your
copyrighted material outside their relationship with you.
</p>
<p>Conveying under any other circumstances is permitted solely under the
conditions stated below.  Sublicensing is not allowed; section 10
makes it unnecessary.
</p>
</li><li> Protecting Users&rsquo; Legal Rights From Anti-Circumvention Law.
<p>No covered work shall be deemed part of an effective technological
measure under any applicable law fulfilling obligations under article
11 of the WIPO copyright treaty adopted on 20 December 1996, or
similar laws prohibiting or restricting circumvention of such
measures.
</p>
<p>When you convey a covered work, you waive any legal power to forbid
circumvention of technological measures to the extent such
circumvention is effected by exercising rights under this License with
respect to the covered work, and you disclaim any intention to limit
operation or modification of the work as a means of enforcing, against
the work&rsquo;s users, your or third parties&rsquo; legal rights to forbid
circumvention of technological measures.
</p>
</li><li> Conveying Verbatim Copies.
<p>You may convey verbatim copies of the Program&rsquo;s source code as you
receive it, in any medium, provided that you conspicuously and
appropriately publish on each copy an appropriate copyright notice;
keep intact all notices stating that this License and any
non-permissive terms added in accord with section 7 apply to the code;
keep intact all notices of the absence of any warranty; and give all
recipients a copy of this License along with the Program.
</p>
<p>You may charge any price or no price for each copy that you convey,
and you may offer support or warranty protection for a fee.
</p>
</li><li> Conveying Modified Source Versions.
<p>You may convey a work based on the Program, or the modifications to
produce it from the Program, in the form of source code under the
terms of section 4, provided that you also meet all of these
conditions:
</p>
<ol class="enumerate" type="a" start="1">
<li> The work must carry prominent notices stating that you modified it,
and giving a relevant date.
</li><li> The work must carry prominent notices stating that it is released
under this License and any conditions added under section 7.  This
requirement modifies the requirement in section 4 to &ldquo;keep intact all
notices&rdquo;.
</li><li> You must license the entire work, as a whole, under this License to
anyone who comes into possession of a copy.  This License will
therefore apply, along with any applicable section 7 additional terms,
to the whole of the work, and all its parts, regardless of how they
are packaged.  This License gives no permission to license the work in
any other way, but it does not invalidate such permission if you have
separately received it.
</li><li> If the work has interactive user interfaces, each must display
Appropriate Legal Notices; however, if the Program has interactive
interfaces that do not display Appropriate Legal Notices, your work
need not make them do so.
</li></ol>
<p>A compilation of a covered work with other separate and independent
works, which are not by their nature extensions of the covered work,
and which are not combined with it such as to form a larger program,
in or on a volume of a storage or distribution medium, is called an
&ldquo;aggregate&rdquo; if the compilation and its resulting copyright are not
used to limit the access or legal rights of the compilation&rsquo;s users
beyond what the individual works permit.  Inclusion of a covered work
in an aggregate does not cause this License to apply to the other
parts of the aggregate.
</p>
</li><li> Conveying Non-Source Forms.
<p>You may convey a covered work in object code form under the terms of
sections 4 and 5, provided that you also convey the machine-readable
Corresponding Source under the terms of this License, in one of these
ways:
</p>
<ol class="enumerate" type="a" start="1">
<li> Convey the object code in, or embodied in, a physical product
(including a physical distribution medium), accompanied by the
Corresponding Source fixed on a durable physical medium customarily
used for software interchange.
</li><li> Convey the object code in, or embodied in, a physical product
(including a physical distribution medium), accompanied by a written
offer, valid for at least three years and valid for as long as you
offer spare parts or customer support for that product model, to give
anyone who possesses the object code either (1) a copy of the
Corresponding Source for all the software in the product that is
covered by this License, on a durable physical medium customarily used
for software interchange, for a price no more than your reasonable
cost of physically performing this conveying of source, or (2) access
to copy the Corresponding Source from a network server at no charge.
</li><li> Convey individual copies of the object code with a copy of the written
offer to provide the Corresponding Source.  This alternative is
allowed only occasionally and noncommercially, and only if you
received the object code with such an offer, in accord with subsection
6b.
</li><li> Convey the object code by offering access from a designated place
(gratis or for a charge), and offer equivalent access to the
Corresponding Source in the same way through the same place at no
further charge.  You need not require recipients to copy the
Corresponding Source along with the object code.  If the place to copy
the object code is a network server, the Corresponding Source may be
on a different server (operated by you or a third party) that supports
equivalent copying facilities, provided you maintain clear directions
next to the object code saying where to find the Corresponding Source.
Regardless of what server hosts the Corresponding Source, you remain
obligated to ensure that it is available for as long as needed to
satisfy these requirements.
</li><li> Convey the object code using peer-to-peer transmission, provided you
inform other peers where the object code and Corresponding Source of
the work are being offered to the general public at no charge under
subsection 6d.
</li></ol>
<p>A separable portion of the object code, whose source code is excluded
from the Corresponding Source as a System Library, need not be
included in conveying the object code work.
</p>
<p>A &ldquo;User Product&rdquo; is either (1) a &ldquo;consumer product&rdquo;, which means any
tangible personal property which is normally used for personal,
family, or household purposes, or (2) anything designed or sold for
incorporation into a dwelling.  In determining whether a product is a
consumer product, doubtful cases shall be resolved in favor of
coverage.  For a particular product received by a particular user,
&ldquo;normally used&rdquo; refers to a typical or common use of that class of
product, regardless of the status of the particular user or of the way
in which the particular user actually uses, or expects or is expected
to use, the product.  A product is a consumer product regardless of
whether the product has substantial commercial, industrial or
non-consumer uses, unless such uses represent the only significant
mode of use of the product.
</p>
<p>&ldquo;Installation Information&rdquo; for a User Product means any methods,
procedures, authorization keys, or other information required to
install and execute modified versions of a covered work in that User
Product from a modified version of its Corresponding Source.  The
information must suffice to ensure that the continued functioning of
the modified object code is in no case prevented or interfered with
solely because modification has been made.
</p>
<p>If you convey an object code work under this section in, or with, or
specifically for use in, a User Product, and the conveying occurs as
part of a transaction in which the right of possession and use of the
User Product is transferred to the recipient in perpetuity or for a
fixed term (regardless of how the transaction is characterized), the
Corresponding Source conveyed under this section must be accompanied
by the Installation Information.  But this requirement does not apply
if neither you nor any third party retains the ability to install
modified object code on the User Product (for example, the work has
been installed in ROM).
</p>
<p>The requirement to provide Installation Information does not include a
requirement to continue to provide support service, warranty, or
updates for a work that has been modified or installed by the
recipient, or for the User Product in which it has been modified or
installed.  Access to a network may be denied when the modification
itself materially and adversely affects the operation of the network
or violates the rules and protocols for communication across the
network.
</p>
<p>Corresponding Source conveyed, and Installation Information provided,
in accord with this section must be in a format that is publicly
documented (and with an implementation available to the public in
source code form), and must require no special password or key for
unpacking, reading or copying.
</p>
</li><li> Additional Terms.
<p>&ldquo;Additional permissions&rdquo; are terms that supplement the terms of this
License by making exceptions from one or more of its conditions.
Additional permissions that are applicable to the entire Program shall
be treated as though they were included in this License, to the extent
that they are valid under applicable law.  If additional permissions
apply only to part of the Program, that part may be used separately
under those permissions, but the entire Program remains governed by
this License without regard to the additional permissions.
</p>
<p>When you convey a copy of a covered work, you may at your option
remove any additional permissions from that copy, or from any part of
it.  (Additional permissions may be written to require their own
removal in certain cases when you modify the work.)  You may place
additional permissions on material, added by you to a covered work,
for which you have or can give appropriate copyright permission.
</p>
<p>Notwithstanding any other provision of this License, for material you
add to a covered work, you may (if authorized by the copyright holders
of that material) supplement the terms of this License with terms:
</p>
<ol class="enumerate" type="a" start="1">
<li> Disclaiming warranty or limiting liability differently from the terms
of sections 15 and 16 of this License; or
</li><li> Requiring preservation of specified reasonable legal notices or author
attributions in that material or in the Appropriate Legal Notices
displayed by works containing it; or
</li><li> Prohibiting misrepresentation of the origin of that material, or
requiring that modified versions of such material be marked in
reasonable ways as different from the original version; or
</li><li> Limiting the use for publicity purposes of names of licensors or
authors of the material; or
</li><li> Declining to grant rights under trademark law for use of some trade
names, trademarks, or service marks; or
</li><li> Requiring indemnification of licensors and authors of that material by
anyone who conveys the material (or modified versions of it) with
contractual assumptions of liability to the recipient, for any
liability that these contractual assumptions directly impose on those
licensors and authors.
</li></ol>
<p>All other non-permissive additional terms are considered &ldquo;further
restrictions&rdquo; within the meaning of section 10.  If the Program as you
received it, or any part of it, contains a notice stating that it is
governed by this License along with a term that is a further
restriction, you may remove that term.  If a license document contains
a further restriction but permits relicensing or conveying under this
License, you may add to a covered work material governed by the terms
of that license document, provided that the further restriction does
not survive such relicensing or conveying.
</p>
<p>If you add terms to a covered work in accord with this section, you
must place, in the relevant source files, a statement of the
additional terms that apply to those files, or a notice indicating
where to find the applicable terms.
</p>
<p>Additional terms, permissive or non-permissive, may be stated in the
form of a separately written license, or stated as exceptions; the
above requirements apply either way.
</p>
</li><li> Termination.
<p>You may not propagate or modify a covered work except as expressly
provided under this License.  Any attempt otherwise to propagate or
modify it is void, and will automatically terminate your rights under
this License (including any patent licenses granted under the third
paragraph of section 11).
</p>
<p>However, if you cease all violation of this License, then your license
from a particular copyright holder is reinstated (a) provisionally,
unless and until the copyright holder explicitly and finally
terminates your license, and (b) permanently, if the copyright holder
fails to notify you of the violation by some reasonable means prior to
60 days after the cessation.
</p>
<p>Moreover, your license from a particular copyright holder is
reinstated permanently if the copyright holder notifies you of the
violation by some reasonable means, this is the first time you have
received notice of violation of this License (for any work) from that
copyright holder, and you cure the violation prior to 30 days after
your receipt of the notice.
</p>
<p>Termination of your rights under this section does not terminate the
licenses of parties who have received copies or rights from you under
this License.  If your rights have been terminated and not permanently
reinstated, you do not qualify to receive new licenses for the same
material under section 10.
</p>
</li><li> Acceptance Not Required for Having Copies.
<p>You are not required to accept this License in order to receive or run
a copy of the Program.  Ancillary propagation of a covered work
occurring solely as a consequence of using peer-to-peer transmission
to receive a copy likewise does not require acceptance.  However,
nothing other than this License grants you permission to propagate or
modify any covered work.  These actions infringe copyright if you do
not accept this License.  Therefore, by modifying or propagating a
covered work, you indicate your acceptance of this License to do so.
</p>
</li><li> Automatic Licensing of Downstream Recipients.
<p>Each time you convey a covered work, the recipient automatically
receives a license from the original licensors, to run, modify and
propagate that work, subject to this License.  You are not responsible
for enforcing compliance by third parties with this License.
</p>
<p>An &ldquo;entity transaction&rdquo; is a transaction transferring control of an
organization, or substantially all assets of one, or subdividing an
organization, or merging organizations.  If propagation of a covered
work results from an entity transaction, each party to that
transaction who receives a copy of the work also receives whatever
licenses to the work the party&rsquo;s predecessor in interest had or could
give under the previous paragraph, plus a right to possession of the
Corresponding Source of the work from the predecessor in interest, if
the predecessor has it or can get it with reasonable efforts.
</p>
<p>You may not impose any further restrictions on the exercise of the
rights granted or affirmed under this License.  For example, you may
not impose a license fee, royalty, or other charge for exercise of
rights granted under this License, and you may not initiate litigation
(including a cross-claim or counterclaim in a lawsuit) alleging that
any patent claim is infringed by making, using, selling, offering for
sale, or importing the Program or any portion of it.
</p>
</li><li> Patents.
<p>A &ldquo;contributor&rdquo; is a copyright holder who authorizes use under this
License of the Program or a work on which the Program is based.  The
work thus licensed is called the contributor&rsquo;s &ldquo;contributor version&rdquo;.
</p>
<p>A contributor&rsquo;s &ldquo;essential patent claims&rdquo; are all patent claims owned
or controlled by the contributor, whether already acquired or
hereafter acquired, that would be infringed by some manner, permitted
by this License, of making, using, or selling its contributor version,
but do not include claims that would be infringed only as a
consequence of further modification of the contributor version.  For
purposes of this definition, &ldquo;control&rdquo; includes the right to grant
patent sublicenses in a manner consistent with the requirements of
this License.
</p>
<p>Each contributor grants you a non-exclusive, worldwide, royalty-free
patent license under the contributor&rsquo;s essential patent claims, to
make, use, sell, offer for sale, import and otherwise run, modify and
propagate the contents of its contributor version.
</p>
<p>In the following three paragraphs, a &ldquo;patent license&rdquo; is any express
agreement or commitment, however denominated, not to enforce a patent
(such as an express permission to practice a patent or covenant not to
sue for patent infringement).  To &ldquo;grant&rdquo; such a patent license to a
party means to make such an agreement or commitment not to enforce a
patent against the party.
</p>
<p>If you convey a covered work, knowingly relying on a patent license,
and the Corresponding Source of the work is not available for anyone
to copy, free of charge and under the terms of this License, through a
publicly available network server or other readily accessible means,
then you must either (1) cause the Corresponding Source to be so
available, or (2) arrange to deprive yourself of the benefit of the
patent license for this particular work, or (3) arrange, in a manner
consistent with the requirements of this License, to extend the patent
license to downstream recipients.  &ldquo;Knowingly relying&rdquo; means you have
actual knowledge that, but for the patent license, your conveying the
covered work in a country, or your recipient&rsquo;s use of the covered work
in a country, would infringe one or more identifiable patents in that
country that you have reason to believe are valid.
</p>
<p>If, pursuant to or in connection with a single transaction or
arrangement, you convey, or propagate by procuring conveyance of, a
covered work, and grant a patent license to some of the parties
receiving the covered work authorizing them to use, propagate, modify
or convey a specific copy of the covered work, then the patent license
you grant is automatically extended to all recipients of the covered
work and works based on it.
</p>
<p>A patent license is &ldquo;discriminatory&rdquo; if it does not include within the
scope of its coverage, prohibits the exercise of, or is conditioned on
the non-exercise of one or more of the rights that are specifically
granted under this License.  You may not convey a covered work if you
are a party to an arrangement with a third party that is in the
business of distributing software, under which you make payment to the
third party based on the extent of your activity of conveying the
work, and under which the third party grants, to any of the parties
who would receive the covered work from you, a discriminatory patent
license (a) in connection with copies of the covered work conveyed by
you (or copies made from those copies), or (b) primarily for and in
connection with specific products or compilations that contain the
covered work, unless you entered into that arrangement, or that patent
license was granted, prior to 28 March 2007.
</p>
<p>Nothing in this License shall be construed as excluding or limiting
any implied license or other defenses to infringement that may
otherwise be available to you under applicable patent law.
</p>
</li><li> No Surrender of Others&rsquo; Freedom.
<p>If conditions are imposed on you (whether by court order, agreement or
otherwise) that contradict the conditions of this License, they do not
excuse you from the conditions of this License.  If you cannot convey
a covered work so as to satisfy simultaneously your obligations under
this License and any other pertinent obligations, then as a
consequence you may not convey it at all.  For example, if you agree
to terms that obligate you to collect a royalty for further conveying
from those to whom you convey the Program, the only way you could
satisfy both those terms and this License would be to refrain entirely
from conveying the Program.
</p>
</li><li> Use with the GNU Affero General Public License.
<p>Notwithstanding any other provision of this License, you have
permission to link or combine any covered work with a work licensed
under version 3 of the GNU Affero General Public License into a single
combined work, and to convey the resulting work.  The terms of this
License will continue to apply to the part which is the covered work,
but the special requirements of the GNU Affero General Public License,
section 13, concerning interaction through a network will apply to the
combination as such.
</p>
</li><li> Revised Versions of this License.
<p>The Free Software Foundation may publish revised and/or new versions
of the GNU General Public License from time to time.  Such new
versions will be similar in spirit to the present version, but may
differ in detail to address new problems or concerns.
</p>
<p>Each version is given a distinguishing version number.  If the Program
specifies that a certain numbered version of the GNU General Public
License &ldquo;or any later version&rdquo; applies to it, you have the option of
following the terms and conditions either of that numbered version or
of any later version published by the Free Software Foundation.  If
the Program does not specify a version number of the GNU General
Public License, you may choose any version ever published by the Free
Software Foundation.
</p>
<p>If the Program specifies that a proxy can decide which future versions
of the GNU General Public License can be used, that proxy&rsquo;s public
statement of acceptance of a version permanently authorizes you to
choose that version for the Program.
</p>
<p>Later license versions may give you additional or different
permissions.  However, no additional obligations are imposed on any
author or copyright holder as a result of your choosing to follow a
later version.
</p>
</li><li> Disclaimer of Warranty.
<p>THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY
APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT
HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM &ldquo;AS IS&rdquo; WITHOUT
WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND
PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE PROGRAM PROVE
DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR
CORRECTION.
</p>
</li><li> Limitation of Liability.
<p>IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR
CONVEYS THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES,
INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES
ARISING OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT
NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR
LOSSES SUSTAINED BY YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM
TO OPERATE WITH ANY OTHER PROGRAMS), EVEN IF SUCH HOLDER OR OTHER
PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
</p>
</li><li> Interpretation of Sections 15 and 16.
<p>If the disclaimer of warranty and limitation of liability provided
above cannot be given local legal effect according to their terms,
reviewing courts shall apply local law that most closely approximates
an absolute waiver of all civil liability in connection with the
Program, unless a warranty or assumption of liability accompanies a
copy of the Program in return for a fee.
</p>
</li></ol>
<h3 class="heading" id="END-OF-TERMS-AND-CONDITIONS">END OF TERMS AND CONDITIONS</h3>
<h3 class="heading" id="How-to-Apply-These-Terms-to-Your-New-Programs">How to Apply These Terms to Your New Programs</h3>
<p>If you develop a new program, and you want it to be of the greatest
possible use to the public, the best way to achieve this is to make it
free software which everyone can redistribute and change under these
terms.
</p>
<p>To do so, attach the following notices to the program.  It is safest
to attach them to the start of each source file to most effectively
state the exclusion of warranty; and each file should have at least
the &ldquo;copyright&rdquo; line and a pointer to where the full notice is found.
</p>
<div class="example smallexample">
<pre class="example-preformatted"><var class="var">one line to give the program's name and a brief idea of what it does.</var>  
Copyright (C) <var class="var">year</var> <var class="var">name of author</var>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <a class="url" href="http://www.gnu.org/licenses/">http://www.gnu.org/licenses/</a>.
</pre></div>
<p>Also add information on how to contact you by electronic and paper mail.
</p>
<p>If the program does terminal interaction, make it output a short
notice like this when it starts in an interactive mode:
</p>
<div class="example smallexample">
<pre class="example-preformatted"><var class="var">program</var> Copyright (C) <var class="var">year</var> <var class="var">name of author</var> 
This program comes with ABSOLUTELY NO WARRANTY; for details type &lsquo;<samp class="samp">show w</samp>&rsquo;.
This is free software, and you are welcome to redistribute it
under certain conditions; type &lsquo;<samp class="samp">show c</samp>&rsquo; for details.
</pre></div>
<p>The hypothetical commands &lsquo;<samp class="samp">show w</samp>&rsquo; and &lsquo;<samp class="samp">show c</samp>&rsquo; should show
the appropriate parts of the General Public License.  Of course, your
program&rsquo;s commands might be different; for a GUI interface, you would
use an &ldquo;about box&rdquo;.
</p>
<p>You should also get your employer (if you work as a programmer) or school,
if any, to sign a &ldquo;copyright disclaimer&rdquo; for the program, if necessary.
For more information on this, and how to apply and follow the GNU GPL, see
<a class="url" href="http://www.gnu.org/licenses/">http://www.gnu.org/licenses/</a>.
</p>
<p>The GNU General Public License does not permit incorporating your
program into proprietary programs.  If your program is a subroutine
library, you may consider it more useful to permit linking proprietary
applications with the library.  If this is what you want to do, use
the GNU Lesser General Public License instead of this License.  But
first, please read <a class="url" href="http://www.gnu.org/philosophy/why-not-lgpl.html">http://www.gnu.org/philosophy/why-not-lgpl.html</a>.
</p>
<hr>
</div>
<div class="unnumbered-level-extent" id="Index">
<div class="nav-panel">
<p>
Previous: <a href="#Copying" accesskey="p" rel="prev">GNU General Public License</a>, Up: <a href="#Top" accesskey="u" rel="up">Introduction</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<h2 class="unnumbered" id="Index-1">Index</h2>
 
<div class="printindex cp-printindex">
<table class="cp-letters-header-printindex"><tr><th>Jump to: &nbsp; </th><td><a class="summary-letter-printindex" href="#Index_cp_letter-B"><b>B</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-C"><b>C</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-F"><b>F</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-I"><b>I</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-L"><b>L</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-M"><b>M</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-O"><b>O</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-P"><b>P</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-R"><b>R</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-S"><b>S</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-U"><b>U</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-W"><b>W</b></a>
 &nbsp; 
</td></tr></table>
<table class="cp-entries-printindex" border="0">
<tr><td></td><th class="entries-header-printindex">Index Entry</th><td>&nbsp;</td><th class="sections-header-printindex"> Section</th></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-B">B</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Basic-Usage-Overview">Basic Usage Overview</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-C">C</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Close-the-client">Close the client</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Connection-to-a-broker">Connection to a broker</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-copyright">copyright</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Copying">Copying</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-F">F</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-flush">flush</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#MQTT-Functions">MQTT Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Function-Reference">Function Reference</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Function-Reference">Function Reference</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-I">I</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Installing-and-loading">Installing and loading</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-L">L</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Loading">Loading</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-M">M</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-MQTT-Functions">MQTT Functions</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#MQTT-Functions">MQTT Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-mqttclient">mqttclient</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#MQTT-Functions">MQTT Functions</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-O">O</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Off_002dline-install">Off-line install</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Online-install">Online install</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-P">P</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-peek">peek</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#MQTT-Functions">MQTT Functions</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-R">R</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-read">read</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#MQTT-Functions">MQTT Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Read-from-subscribed-Topics">Read from subscribed Topics</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-S">S</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-subscribe">subscribe</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#MQTT-Functions">MQTT Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Subscribe-to-a-Topic">Subscribe to a Topic</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-U">U</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-unsubscribe">unsubscribe</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#MQTT-Functions">MQTT Functions</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-W">W</th><td></td><td></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-warranty">warranty</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Copying">Copying</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-write">write</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#MQTT-Functions">MQTT Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Write-to-a-Topic">Write to a Topic</a>:</td><td>&nbsp;</td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
</table>
<table class="cp-letters-footer-printindex"><tr><th>Jump to: &nbsp; </th><td><a class="summary-letter-printindex" href="#Index_cp_letter-B"><b>B</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-C"><b>C</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-F"><b>F</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-I"><b>I</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-L"><b>L</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-M"><b>M</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-O"><b>O</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-P"><b>P</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-R"><b>R</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-S"><b>S</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-U"><b>U</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-W"><b>W</b></a>
 &nbsp; 
</td></tr></table>
</div>
 
</div>
</div>