function(page) {
    var regex = /<picture class="[^"]*cropped-strip[^<]*<img[^>]* src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
