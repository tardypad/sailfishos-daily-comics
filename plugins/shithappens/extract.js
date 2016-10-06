function(page) {
    var regex = /<img[^>]*src="(.*\/cartoons\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
