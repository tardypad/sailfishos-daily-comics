function(page) {
    var regex = /<div id="the_strip"><img src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
