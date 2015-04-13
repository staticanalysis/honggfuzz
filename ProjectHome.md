# honggfuzz #

**Description**
  * A general-purpose, easy-to-use fuzzer with interesting analysis options. See [README](README.md) wiki page for more details
  * Supports hardware-based [feedback-driven fuzzing](https://code.google.com/p/honggfuzz/wiki/FeedbackDrivenFuzzing) (requires Linux and a supported CPU model)
  * It works, at least, under GNU/Linux and FreeBSD (possibly under Mac OS X as well)
  * [Can fuzz long-lasting processes](https://code.google.com/p/honggfuzz/wiki/AttachingToPid) (e.g. network servers like Apache's httpd and ISC's bind)
  * It's been used to find a few interesting security problems in major software; examples:
    * FreeType 2 project: [CVE-2010-2497](https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2010-2497), [CVE-2010-2498](https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2010-2498), [CVE-2010-2499](https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2010-2499), [CVE-2010-2500](https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2010-2500), [CVE-2010-2519](https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2010-2519), [CVE-2010-2520](https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2010-2520), [CVE-2010-2527](https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2010-2527)
    * [Multiple bugs in the libtiff library](http://bugzilla.maptools.org/buglist.cgi?query_format=advanced;emailreporter1=1;email1=robert@swiecki.net;product=libtiff;emailtype1=substring)
    * [Multiple bugs in the librsvg library](https://bugzilla.gnome.org/buglist.cgi?query_format=advanced;emailreporter1=1;email1=robert%40swiecki.net;product=librsvg;emailtype1=substring)
    * [Multiple bugs in the poppler library](http://lists.freedesktop.org/archives/poppler/2010-November/006726.html)
    * [Multiple exploitable bugs in IDA-Pro](https://www.hex-rays.com/bugbounty.shtml)


**Code**
  * Current version: 0.5 ([ChangeLog](http://code.google.com/p/honggfuzz/source/browse/trunk/ChangeLog))
  * Source code: [Link](https://code.google.com/p/honggfuzz/source/browse/#svn%2Ftrunk)
  * Tarball: [Honggfuzz 0.5](https://docs.google.com/file/d/0B86hdL7CeBvAX1NzMkMtUzN4Rms/view), [Direct download link](https://docs.google.com/uc?id=0B86hdL7CeBvAX1NzMkMtUzN4Rms&export=download) and [earlier versions](https://drive.google.com/folderview?id=0B86hdL7CeBvAfmJXcTJCeTJSeFdHd3E5Q3VGZFdCY192aVBxcHJSbkIyUVZGMG9ualJ6aE0&usp=sharing)

**Requirements**
  * (under Linux) - BFD library (libbfd-dev) and LibUnwind (libunwind-dev/libunwind8-dev)
  * (under FreeBSD) - gmake