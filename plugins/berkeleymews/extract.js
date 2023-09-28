function(page) {
    var regex = /<img[^>]* src="([^"]+)"[^>]* class="aligncenter size-full/;
    var match = regex.exec(page);
    return match[1];
}
