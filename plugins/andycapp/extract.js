function(page) {
    var regex = /<img[^>]*class="strip" src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
