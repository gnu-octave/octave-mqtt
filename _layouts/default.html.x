<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport"
          content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" type="text/css"
          href="https://cdn.datatables.net/v/dt/jq-3.3.1/dt-1.10.25/sc-2.0.4/datatables.min.css">
    <link rel="stylesheet"
          href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.4/css/all.min.css"
          integrity="sha512-1ycn6IcaQQ40/MKBW2W4Rhis/DbILU74C1vSrLJxCq57o941Ym01SwNsOMqvEBFlcgUa6xLiPY/NS5R+E6ztJQ=="
          crossorigin="anonymous" referrerpolicy="no-referrer">
    <link rel="stylesheet"
          href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.0/dist/css/bootstrap.min.css"
          integrity="sha384-KyZXEAg3QhqLMpG8r+8fhAXLRk2vvoC2f3B09zVXn8CA5QIVfZOJ3BCsw2P0p/We"
          crossorigin="anonymous">
    <link rel="stylesheet"
	  href="{{site.url}}/assets/style.css">
    <script src="https://cdn.datatables.net/v/dt/jq-3.3.1/dt-1.10.25/sc-2.0.4/datatables.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.0/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-U1DAWAznBHeqEIlVSCgzq+c9gqGAJn5c/t99JyeKa9xxaYpSvHU5awsuZVVFIhvj"
            crossorigin="anonymous"></script>

    <title>{{ page.title | default: site.title }}</title>
  </head>
  <body>
    <style>
      body {
        background-color: #ffffff;
	height: 100%
      }

      .afterheader {
        position: fixed;
        top: 56px;
	/* allow for footer */
        bottom: calc(1.5em); 
        left: 0;
      }

      .fullheight {
	 height: 100%
      }

      .footer {
	 max-height:1.5em;
      }

      .pad-left-1 {
	 padding-left: 1em
      }

      .mainscroll {
         overflow-y: scroll;
      }

      .mysidebar {
        box-shadow: 0 2px 5px 0 rgb(0 0 0 / 5%), 0 2px 10px 0 rgb(0 0 0 / 5%);
        z-index: 600;
      }

      .myoverflow {
        overflow-y: scroll;
      }

    </style>

    <!-- top nav bar -->
    <header>
      <nav id="main-navbar" class="navbar navbar-expand-md navbar-dark bg-dark fixed-top">
        <div class="container-fluid">
	  <a class="navbar-brand" href="{{site.url}}">
	    <img src="{{ site.url }}/{{ site.logo }}"
	         width="25" height="25" alt="{{ site.title }}"
                 class="d-inline-block align-top">
            {{ site.title }}
          </a>
          <button class="navbar-toggler" type="button"
            data-bs-toggle="collapse" data-bs-target="#navbarNav"
            aria-controls="navbarNav" aria-expanded="false"
            aria-label="Toggle navigation"
          >
            <span class="fas fa-bars"></span>
          </button>
          <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav">
              <li class="nav-item">
                <a class="nav-link" href="https://gnu-octave.github.io/packages/">
                  <img src="{{ site.url }}{{'/assets/octave-logo.svg'}}"
                       width="16" height="16" alt="GNU Octave"
                       class="d-inline-block align-center">
                  Octave Packages
                </a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="https://www.octave.org">
                  <i class="fas fa-home"></i>
                  GNU Octave website
                </a>
              </li>
            </ul>
	  </div>
        </div>
      <nav>
    </header>

    <!-- main section -->
    <div class="container-fluid afterheader">
      <div class="row fullheight">
        <!-- left navbar - is set no expand when > md -->
        <div class="col-sm-1 col-md-3 col-lg-2 col-xl-2 mysidebar" id="mysidebar">
          <nav class="navbar navbar-expand-md bg-white fixed-left">
            <button class="navbar-toggler pull-right" type="button"
              data-bs-toggle="collapse" data-bs-target="#navbarLeft"
              aria-controls="navbarLeft" aria-expanded="true"
              aria-label="Toggle navigation"
            >
              <span class="fas fa-bars"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarLeft">
              <ul class="collapse show list-group list-group-flush">
                {%- if page.navigation -%}
                  {%- for nav in page.navigation -%}
                    {% if nav.url %}
		    <li class="list-group-item p-1"><a href="{{site.url}}{{nav.url}}">{{nav.name}}</a></li>
                    {% else %}
                      <li class="list-group-item p-1"><b>{{nav.name}}</b></li>
                    {%- endif -%}
                  {%- endfor -%}
                {%- else -%}
	          <li class="list-group-item py-1"><a href="{{site.url}}/index">Overview</a></li>
	          <li class="list-group-item py-1"><a href="{{site.url}}/functions">Function Reference</a></li>
                  <li class="list-group-item py-1"><a href="{{site.url}}/news">News</a></li>
                {%- endif -%}
              </ul>
            </div>
          </nav>
        </div>
        <!-- main page -->
        <div class="col-sm-11 col-md-9 col-lg-10 col-xl-10 mainscroll" id="mainscroll">
          <h1>{{ page.title | default: site.title }}</h1><hr/>
          {{content}}
        <div>
      </div>
    </div>

    <!-- footer -->
    <div class="bg-dark text-light fixed-bottom footer">
      <div class="pad-left-1 small">&copy; 2022 - {{ site.author | default: "The Octave Forge Community" | xml_escape | textilize }}<div>
    </div>

    <script>
      function getOffset(el) {
        const rect = el.getBoundingClientRect();
        return {
          left: rect.left + window.scrollX,
          top: rect.top + window.scrollY,
          width: rect.width,
          height: rect.height
        };
      }
      function resizeDivs() {
	var p = getOffset(document.getElementById('mainscroll'));
	var pp = getOffset(document.getElementById('mainscroll').parentElement);
        //document.getElementById('mainscroll').style.height = (pp.height - (p.top - pp.top)) + 'px'
        //document.getElementById('mysidebar').style.height = (pp.height - (p.top - pp.top)) + 'px'
      }
    
      window.onload = resizeDivs;
      window.onresize = resizeDivs;

    </script>
  </body>
</html>
