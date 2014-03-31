# gigya_top_comments

## Dependencies
- Contributed module dependencies ()
- Custom module dependencies ()

## Version / Author
1.0(d6) /Hans Gutknecht, hans.gutknecht@mlssoccer.com
1.1(d7) /Louis Jimenez, louis.jimenez@mlssoccer.com

## Description

To determine “popular” content, Gigya offers services via their REST API. We implemented the getTopStreams method to acquire a list of popular content rated based on comment count. Unfortunately the defined maxStreamAge “The number of days. The method retrieves only streams that were created within the past maxStreamAge days. The default is 3 days. The maximum is 7 days.” turned out to be a hard reset on the returned content. Meaning once the time limit was met, items were immediately dropped of the list of returned items. This implementation was a bit jarring, content that had high comment counts were being dropped off the results by time and not based off of their actually popularity.

We decided to implement the algorithm used by Hacker News described in this blog post http://amix.dk/blog/post/19574

To start using the Gigya Top Comments module, add your Gigya API key and Secret key to to the admin screen. Each time cron is run, the module will retrieve the top comment streams from Gigya and display the matching content in the Gigya Top Comments Block. If the block is not displaying content or you see the error message "Content not found. Stream ID does not match any node ID's" then your database may be out of date. Make sure you are working with the latest production copy of your db so that the streams ID's can be correctly match with nodes.
