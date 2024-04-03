//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2019, 2023 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>
#import <Diffusion/PTDiffusionFeature.h>

@class PTDiffusionTopicView;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief This feature allows a client session to manage topic views.

 A topic view maps one part of a server's topic tree to another. It
 dynamically creates a set of <em>reference topics</em> from a set of
 <em>source topics</em>, based on a declarative <em>topic view
 specification</em>. The capabilities of topic views range from simple
 mirroring of topics within the topic tree to advanced capabilities including
 publication of partial values, expanding a single topic value into many
 topics, changing topic values, inserting values from other topics, throttling
 the rate of publication, and applying a fixed delay to the publication.

 A topic view can also map topics from another server (in a different
 cluster). This capability is referred to as 'remote topic views'. The view
 can specify the server that the <em>source topics</em> are hosted on in terms
 of a <em>remote server</em> (see {@link PTDiffusionRemoteServersFeature} for details of how to
 create and maintain remote servers).

 Each reference topic has a single source topic and has the same topic type as
 its source topic. Reference topics are read-only (they cannot be updated),
 nor can they be created or removed directly. Otherwise, they behave just like
 standard topics. A client session can subscribe to a reference topic, and can
 fetch the reference topic's current value if it has one.

 The source topics of a topic view are defined by a topic selector. One or
 more reference topics are created for each source topic, according to the
 topic view. If a source topic is removed, reference topics that are derived
 from it will automatically be removed. If a topic is added that matches the
 source topic selector of a topic view, corresponding reference topics will be
 created. Removing a topic view will remove all of its reference topics.


 ## Topic view specifications

 The following is a simple topic view specification that mirrors all topics
 below the path `a` to reference topics below the path `b`.

 <pre>
 map ?a// to b/<path(1)>
 </pre>

 A topic view with this specification will map a source topic at the path
 `a/x/y/z` to a reference topic at the path `b/x/y/z`.
 The specification is simple, so the reference topic will exactly mirror the
 source topic.

 A topic view specification comprises three main parts:

 <ul>
    <li>The <em>mapping</em> part which specifies the source topics to map from
        and the mappings to target reference topics.
    <li>Optional <em>transformations</em> which transform the topic value in some
        way.
    <li>Optional <em>options</em> which specify other changes that the view may
        apply.
 </ul>

 Mapping comprises:
 <ul>
    <li>The <em>source topic</em> clause identifying the source topics that the
        view can apply to.
    <li>The optional <em>from</em> clause which may identify a remote server that
        hosts the source topics.
    <li>The <em>path mapping</em> clause which determines how reference topic
        paths are derived from the source topic paths, and when expanding to more
        than one reference topic, from where the values are obtained.
 </ul>

 Transformations can be:
 <ul>
    <li><em>patch</em> transformation(s) specifying that a JSON patch is applied
        to the reference topic value.
    <li><em>process</em> transformations that allow conditional processing and/or
        calculations to be applied to the reference topic value.
    <li><em>insert</em> transformation(s) specifying that values from other
        topics are inserted into the reference topic value.
 </ul>

 Options can be:
 <ul>
    <li>The <em>topic property mapping</em> clause determines how reference topic
        properties are derived from source topic properties.
    <li>The <em>value mapping</em> clause determines how reference topic values
        are derived from source topic or expanded values.
    <li>The <em>throttle</em> clause constrains the rate at which each reference
        topic is updated when its source topic is updated.
    <li>The <em>delay by</em> clause causes a change to a view's source topic to
        be delayed by a fixed time before it is reflected in reference topics.
    <li>The <em>separator</em> clause can define a replacement path separator for
        values extracted using the scalar or expand directives.
    <li>The <em>type</em> clause can specify that the reference topic that is
        created is of a different {@link PTDiffusionTopicType} from the selected source topic.
 </ul>

 ### Mapping
 #### Source topic clause

 The source topic clause begins with the `map` keyword and is followed
 by a topic selector. These topic selectors follow the same parsing rules as
 other topic selectors.

 When evaluating a topic view, all topics in the topic tree that match the
 source topic selector are considered (excluding
 {@link PTDiffusionTopicType#PTDiffusionTopicType_Routing Routing} topics).
 However, if a view specification uses some feature that can
 only be applied to JSON topics then only JSON topics will be selected.

 Reference topics are valid source topics. In particular, chaining of topic
 views is supported; that is, a reference topic created by one topic view can
 be the source topic of another topic view. Additionally, a reference topic
 can be the source topic of a routing topic subscription.


 #### From clause

 The `from` clause optionally follows the source topic clause. It begins with
 the `from` keyword and is followed by a remote server name. The name
 refers to a remote server created using the {@link PTDiffusionRemoteServersFeature}
 feature.

 The presence of the clause indicates that the source topics will be selected
 from the specified server and not from the local server.

 Further details regarding the processing of remote topic views are given
 below.


 #### Path mapping clause

 The paths of reference topics are derived from the source topic according to
 the path mapping clause. The path mapping allows the source topic path and
 the value of the source topic to determine the path of the reference topic.
 In addition the path mapping can include <em>expand</em> directives which
 allow objects and arrays in JSON source topic values to be expanded to
 produce many reference topics.

 A path mapping clause begins with the `to` keyword and is followed by a
 path mapping template. A path mapping template is a topic path with embedded
 <em>directives</em>. Directives are evaluated when creating the topic
 reference and substituted into the topic path. Directives are delimited by
 angle brackets (`<`, `>`) and consist of the name of the
 directive and a list of parameters. The parameter list is comma-separated and
 surrounded by parentheses (`(`, `)`).

 The following path mapping directives are supported:

 #### Source path directives

 Source path directives extract a portion of the source path and are
 parameterized by the index of the start part of the source path and the
 number of parts to include. The number of parts parameter is optional – if it
 is missing, the selection extends to the end of the source path. The syntax
 is <code><path(<em>start</em>, <em>number</em>)></code>, or
 <code><path(<em>start</em>)></code> when the number of parts parameter
 is omitted.

 For example, given the source path `a/b/c/d`, the source path directive
 `<path(1, 2)>` is mapped to the reference topic path `b/c`, and
 the source path directive `<path(2)>` is mapped to the reference topic
 path `c/d`.

 #### Source value ("scalar") directives

 Source value directives are only applied to
 {@link PTDiffusionTopicType#PTDiffusionTopicType_JSON JSON}
 source topics or {@link PTDiffusionTopicType#PTDiffusionTopicType_TimeSeries Time Series}
 source topics with a JSON event type; if the path
 mapping contains a source value directive, topics with other topic types matching
 the source topic selector are ignored. Source value directives use the keyword
 `scalar` and are parameterized by a single
 <a href="https://tools.ietf.org/html/rfc6901"> JSON pointer</a> that extracts
 a scalar value from the source (or current) value. A scalar value is a
 string, a number, `true`, `false`, or `null`, that is,
 anything other than an array or an object. If the JSON pointer does not refer
 to a scalar value in the source (or current) value, no reference topic will
 be created. This includes cases where the JSON pointer refers to an array or
 an object), or when no part of the source value is selected.

 Deriving the reference topic paths from part of the source topic value
 effectively creates a secondary index on the value. For source value
 directives to work efficiently, the selected scalar values should be
 relatively stable. If an update to the source topic changes the selected
 scalar value, the corresponding reference topic will be removed and a new
 reference topic will be created.

 For example, given a source value of

 <pre>
 {
     "account" : "1234",
     "balance" : { "amount" : 12.57, "currency" : "USD" }
 }
 </pre>

 and the source value directive
 `currency/<scalar(/balance/currency)</account/<scalar(/account)>`, the
 reference topic path will be `currency/USD/account/1234`.

 If the extracted value is a string, it is copied literally to the reference
 topic path. A value that contains path separators (`/`) will create a
 reference topic path with more levels than the path mapping template. Use the
 separator directive to replace path separator with an alternative string.

 An extracted value of `null` will be copied to the reference topic path
 as the string `"null"`.

 #### Expand value directives

 Expand value directives are only applied to
 {@link PTDiffusionTopicType#PTDiffusionTopicType_JSON JSON}
 source topics; if the path mapping contains an expand value directive,
 non-JSON topics matching the source topic selector are ignored.

 Expand value directives use the keyword `expand` and are parameterized
 by one or two <a href="https://tools.ietf.org/html/rfc6901">JSON
 pointers</a>.

 The first pointer indicates the element within the value to be expanded, and
 if omitted, the value is expanded from the root. Expansion of a source topic
 indicates that every direct child of the element pointed to by the expand
 pointer will be used to create a new reference topic (or provide input to
 later expand or scalar directives). For example `<expand()>` would
 expand every child item in the source value and `<expand(/account)>`
 would expand every child of the `account` value in the source value.
 The specified value could be an object, an array or even a scalar value, but
 a scalar value would expand to only a single new value.

 The optional second parameter of the expand directive specifies a pointer to
 a scalar value within the expanded value which will be used to derive the
 path fragment of the reference topic path. If the second pointer is not
 specified or no scalar value is found for the pointer, the path fragment is
 taken from the key (if the child value is an object) or the index (if the
 child value is an array). Scalar child values will expand to a reference
 topic but will not add anything to the generated path. For example
 `expand(,/name)>` would expand from the root of the source value and
 each child value path fragment would be obtained from the scalar value with
 the key `name`.

 So if a source topic had a value of

 <pre>
 {
 "values": [1, 5, 7]
 }
 </pre>

 a path mapping of `value<expand(/values)>` would expand the value to
 the following reference topics:-
 <p>
 path `value0` with a value of `1`<br>
 path `value1` with a value of `5`<br>
 path `value2` with a value of `7`<br>
 <p>
 Expand directives can be nested (i.e. there can be more than one expand
 directive in a path mapping). In this case a second expand directive will use
 the value from the previous expand as its source (root) value and not the
 value of the source topic. This also applies to scalar directives that follow
 an expand directive.
 <p>
 If expansion causes more than one mapping to the same topic path, only the
 first encountered will be created and updated.
 <p>
 Expanding source topic values effectively creates secondary indices on the
 value. For expanded value directives to work efficiently, the value selected
 for expansion should be relatively stable in terms of the children it
 contains. If an update to the source topic changes the children of the
 expanded value, then corresponding reference topics will be removed and
 created. Updates should generally be limited to changing values within the
 expanded values.</dd>

 ### Transformations

 Transformations are specified after the mapping and before any options.
 Transformations can only be applied to
 {@link PTDiffusionTopicType#PTDiffusionTopicType_JSON JSON} topics.

 Transformations are applied to the value extracted from the source topic in
 the order specified. There can be any number of transformations interspersed
 with one another and the value from one will be that which is input to the
 next. The only restrictions is that all <b>insert</b> transformations must
 occur at the end, after any others.

 A transformation is applied to the current value within a view processing
 chain, so if a transformation occurs after an expand then it will be applied
 to each expanded value.

 #### Process transformations

 Process transformations may be used to apply conditional processing to a
 value (optionally determining whether a reference topic is created) and/or
 change the value in some way (for example, by applying some calculation to a
 field within the value).

 The format of a process transformation is:
 <pre>
 <b>process {</b><i>statement</i><b>}</b>
 </pre>

 Where the <i>statement</i> can be:
 <ul>
    <li>Operations(s). <br>
        One or more operations separated by ';'.
    <li>A conditional statement. <br>
        Comprising one or more conditions with operations to perform if they are
        satisfied.
 </ul>

 For example, the following topic view specification could be used to write a
 field into the value of the reference topic:

 <pre>
 map ?a// to b/<path(1)> process {set(/Name, 'John')};
 </pre>

 The following example shows a simple conditional statement which would only
 generate reference topics if the value of field <code>/Price</code> was
 greater than 50:

 <pre>
 map ?a// to b/<path(1)> process {if '/Price gt 50' continue};
 </pre>

 And the following shows a more complex statement which would set a field
 according to the value of the input field <code>/Price</code>:

 <pre>
 map ?a// to b/<path(1)> process {if '/Price lt 50' set(/Tier, 1) elseif '/Price gt 50' set(/Tier, 2)};
 </pre>

 <dl>
    <dt>
        Process operations
    </dt>

     <dd>
         The following operations are supported:

         <table border=1>
            <tr>
                <th style="text-align:left;">
                    <b>Operation</b>
                </th>
                <th style="text-align:left;">
                    <b>Description</b>
                </th>
            </tr>
            <tr>
                <td style="text-align:left;">
                    <b>set(</b><i>pointer</i>, <i>value</i><b>)</b>
                </td>
                <td style="text-align:left;">
                    Sets the field indicated by the JSON <i>pointer</i> to an absolute <i>value</i>.
                    If the field does not exist it will be created.
                    The <i>value</i> can be an integer (e.g. 123), a String (e.g. 'XYZ'),
                    or a boolean (e.g. true or false).

                    For example:

                    <pre>set(/Name, 'John')</pre>

                    If a hierarchic pointer is specified, the parent object or array must exist.
                </td>
            </tr>
            <tr>
                <td style="text-align:left;">
                    <b>set(</b><i>pointer</i>, <b>calc</b> <i>calculation</i><b>)</b>
                </td>
                <td style="text-align:left;">
                    Sets the field indicated by the JSON <i>pointer</i> to a value which is the
                    result of the specified <i>calculation</i>. If the field does not exist it
                    will be created. The calculation can include fields within the input value.
                    The calculation is specified as a quoted string. See below for a detailed
                    description of calculations.

                    For example:

                    <pre>set(/DoubleValue, calc '/Value * 2')</pre>

                    If a hierarchic pointer is specified, the parent object or array must exist.
                </td>
            </tr>
            <tr>
                <td style="text-align:left;">
                    <b>remove(</b><i>pointer</i><b>)</b>
                </td>
                <td style="text-align:left;">
                    Removes the JSON item at the specified <i>pointer</i>.
                    Unlike JSON patch, if the item does not exist the operation does not fail.
                </td>
            </tr>
            <tr>
                <td style="text-align:left;">
                    <b>continue</b>
                </td>
                <td style="text-align:left;">
                    This is a special operation that indicates that the topic view evaluation
                    should continue with the value as it is. This is only for use with conditional
                    statements as the default behaviour of a conditional statement is not to
                    proceed if no condition is satisfied.
                </td>
            </tr>
         </table>

         Operations can be chained by separating them with a ';' as shown in the example below:

         <pre>
         set(/Amount, calc '/Value * /Number'); remove(/Value); remove(/Number)
         </pre>

         In this case the operations are all performed on the original value, creating
         a chain of deltas which are only applied to the original value at the end. If
         the 'set' operation fails no reference topic would be generated, however,
         processing will continue if the fields specified in the 'remove's are not
         present.
     </dd>

     <dt>
        Process calculations
     </dt>

     <dd>
         A calculation may be specified as the value of a <b>set</b> operation. A
         calculation is a simple arithmetic calculation upon integer fields. If
         applied to a non integer field the evaluation will not proceed. Floating
         point calculations are not supported.

         Arithmetic operators supported are `+`, `-`, `*` and `/`.

         Examples of calculations are:

         <pre>
         set(/Value, calc '/Value * 2')
         set(/Result, calc '/Value / 2')
         set(/Bonus, calc '/Salary + 1000')
         set(/Bonus, calc '/Salary + 1000 + /Age * 10')
         </pre>

         Standard operator precedence is applied, so in the last example above we have
         `(/Salary + 1000 + (/Age * 10))` not `((/Salary + 1000 + /Age) * 10)`.
         Brackets may be used to override this.
     </dd>

     <dt>
        Process conditional statements
     </dt>

     <dd>
         A conditional statement is made up of an <b>if</b> clause, optionally
         followed by one or more <b>elseif</b> clauses and an optional final <b>else</b>
         clause.

         The <b>if</b> clause takes the form:

         <pre>
         <b>if</b> <i<condition operation(s)</i>
         </pre>

         Where the <i>condition</i> is a quoted string as described in detail below
         and the <i>operation(s)</i> is as described previously. If the condition is
         satisfied, the operations are applied to the value and the process is complete.
         If the condition is not satisfied, processing moves on to any
         <b>elseif</b> or <b>else</b> clauses that follow, but if there are none, the
         topic view evaluation does not proceed and no reference topic is created.

         An <b>elseif</b> (else if) clause takes the form:

         <pre>
            <b>elseif</b> <i>condition operation(s)</i>
         </pre>

         If the condition is satisfied, the operations are applied to the value and
         the process is complete. If the condition is not satisfied, processing moves
         on to any <b>elseif</b> or <b>else</b> clauses that follow, but if there are
         none, the topic view evaluation does not proceed and no reference topic is
         created. Note that <b>elseif</b> cab be abbreviated to <b>elsf</b>.

         An <b>else</b> clause takes the form:

         <pre>
            <b>else</b> <i>operation(s)</i>
         </pre>

         And will only be reached if no previous <b>if</b> or <b>elseif</b> conditions
         were satisfied. If reached then the operations are applied to the value and
         the topic view evaluation proceeds. The <b>continue</b> operation may be used
         to proceed with an unchanged value.
     </dd>

     <dt>
        Process conditions
     </dt>

     <dd>
         A condition is of the form:

         <pre>
         <i>pointer operator constant</i>
         </pre>

         Where <i>pointer</i> is a JSON pointer, <i>operator</i> is a relational
         operator and <i>constant</i> is a string, integer, or a boolean value.

         For example:

         <pre>
         /Age > 40
         /Name = 'Bill'
         /Manager eq true
         </pre>

         Operators allowed are:
         <table border=1>
            <tr>
                <th style="text-align:center;">Operator</th>
                <th style="text-align:center;">Variant</th>
                <th style="text-align:center;">Description</th>
                <th style="text-align:center;">Supported JSON types</th>
            </tr>
            <tr>
                <td style="text-align:center;">=</td>
                <td style="text-align:center;">eq</td>
                <td style="text-align:center;">Equals</td>
                <td style="text-align:center;">All</td>
            </tr>
            <tr>
                <td style="text-align:center;">&gt;</td>
                <td style="text-align:center;">gt</td>
                <td style="text-align:center;">Greater than</td>
                <td style="text-align:center;">Integer only</td>
            </tr>
            <tr>
                <td style="text-align:center;">&lt;</td>
                <td style="text-align:center;">lt</td>
                <td style="text-align:center;">Less than</td>
                <td style="text-align:center;">Integer only</td>
            </tr>
            <tr>
                <td style="text-align:center;">!=</td>
                <td style="text-align:center;">ne</td>
                <td style="text-align:center;">Not equals</td>
                <td style="text-align:center;">All</td>
            </tr>
            <tr>
                <td style="text-align:center;">&gt;=</td>
                <td style="text-align:center;">ge</td>
                <td style="text-align:center;">Greater than or equal</td>
                <td style="text-align:center;">Integer only</td>
            </tr>
            <tr>
                <td style="text-align:center;">&lt;=</td>
                <td style="text-align:center;">le</td>
                <td style="text-align:center;">Less than or equal</td>
                <td style="text-align:center;">Integer only</td>
            </tr>
         </table>

         Compound conditions are supported by means of boolean operators:
         `|` or `or`
         `&` or `and`

         For example:

         <pre>
         /Age = 50 ot /Age > 80
         /Age gt 50 & /Department eq 'Accounts'
         </pre>

         Normal boolean precedence applies but brackets can be used to control
         precedence. For example:

         <pre>
         (/Age > 50 or /Department eq 'Accounts`) and /Band > 3
         </pre>

         Boolean 'not' is also allowed:

         <pre>
         not (/Age < 65 or Retired eq false)
         </pre>
     </dd>
 </dl>

 #### Patch Transformations

 Patch transformations indicate that a JSON patch is to applied to the
 value.

 The format of a patch clause is:

 <pre>
 <b>patch</b> 'patch string'
 </pre>

 The patch string should be formatted according to the JSON Patch standard
 (see <a href="https://tools.ietf.org/html/rfc6902"> RFC 6902: JavaScript
 Object Notation (JSON) Patch</a>).

 Patches are a sequence of JSON Patch operations contained in an array. They
 are applied as an atomic update to the previous value if the resulting update
 is successfully calculated. The following patch will check the value at a
 specific key and update if the expected value is correct:

 <pre>
 [{"op": "test", "path": "/price", "value": 22},
  {"op": "add", "path": "/price", "value": 23}]
 </pre>

 The available operations are:
 <ul>
    <li><strong>Add:</strong> <code>{"op": "add", "path": "/a/b/c", "value": [ "foo", "bar" ] }</code>
    <li><strong>Remove:</strong> <code>{"op": "remove", "path": "/a/b/c" }</code>
    <li><strong>Replace:</strong> <code>{"op": "replace", "path": "/a/b/c", "value": 43 }</code>
    <li><strong>Move:</strong> <code>{"op": "move", "from": "/a/b/c", "path": "/a/b/d" }</code>
    <li><strong>Copy:</strong> <code>{"op": "copy", "from": "/a/b/c", "path": "/a/b/e" }</code>
    <li><strong>Test:</strong> <code>{"op": "test", "path": "/a/b/c", "value": "foo" }</code>
 </ul>

 The test operation checks that the CBOR representation of the value of a
 topic is identical to the value provided in the patch after converting it to
 CBOR. If the value is represented differently as CBOR, commonly due to
 different key ordering, then the patch will return the index of the failed
 operation. e.g the values <code>{"foo": "bar", "count": 43}</code> and
 <code>{"count": 43, "foo": "bar"}</code> are unequal despite semantic equality
 due to the differences in a byte for byte comparison.

 The following patch clause would add the 'price' field and remove the 'name'
 field from an input JSON object.

 <pre>
 patch '[{"op": "add", "path": "/price", "value": 22},
         {"op": "remove", "path": "/name"}]'
 </pre>

 Patches can only be applied to JSON arrays or objects and if they fail to
 apply, no resulting reference topic will be created by the view. If an update
 patch fails, any previously created reference topic would be removed.


 #### Insert transformations

 Insert transformations are used to insert a value from another topic into the
 current value.

 The name of the topic to insert from can be specified in a similar way to the
 path mapping in that constants, path directives, and scalar directives (but
 not expand directives) may be used.

 The value from the insertion topic (if found) is inserted into the 'current'
 value at a specified key position. The current value may be the source topic
 value, the value output from expand directives (in which case the insertion
 applies to each value), or the value from a previous transformation.
 Insertion topics may be type {@link PTDiffusionTopicType#PTDiffusionTopicType_JSON JSON},
 {@link PTDiffusionTopicType#PTDiffusionTopicType_String String},
 {@link PTDiffusionTopicType#PTDiffusionTopicType_Int64 Int64},
 or {@link PTDiffusionTopicType#PTDiffusionTopicType_Double Double}.

 If, when evaluating a topic view, the insertion topic is not found (or the
 specified key within it is not found), or it is of an unsupported topic type,
 an optional default value may be inserted, but if no default is specified
 then no insertion takes place and the value is passed to the derived
 reference topic unchanged.

 The values of the insertion topics are only taken at the point when the
 source topic is evaluated against the topic view (i.e. when the source topic
 is updated). Changes to the value of the insertion topic that occur in the
 interim are not applied to the derived reference topics.

 The format of an insert transformation is

 <pre>
 <b>insert</b> <i>path</i> [<b>key</b> <i>fromKey</i>] <b>at</b> <i>insertionKey</i>
 [<b>default</b> <i>defaultValue</i>]
 </pre>

 The <i>path</i> is specified in exactly the same way as for the path mapping
 clause, except it may not contain expand directives. <em>path</em> directives
 operate on the path of the source topic, whereas <em>scalar</em> directives
 operate on the 'current' value as defined previously.

 <b>key</b> is optional and can specify a <i>fromKey</i> which is a JSON
 pointer indicating the data within the insertion topic that is to be
 inserted. If no key is specified then the whole of the insertion topic value
 is inserted.

 <b>at</b> specifies the <i>insertionKey</i> which is a JSON pointer
 indicating where to insert the insertion topic value. If a value already
 exists at the specified key then it is replaced otherwise it is inserted.
 Insertion can only occur if the parent of the key exists in the value and is
 of a compatible type. Array pointers may only be used to replace existing
 entries or append one greater than the last entry. The special pointer value
 <code>/-</code> may be used to append to the end of an existing array.

 <b>default</b> is optional and may be used to specify a string
 <i>defaultValue</i> to be inserted if the insertion topic does not exist, it
 is of an unsupported topic type, or the specified key within it could not be
 found.

 The following insert transformation would cause the whole value of the topic
 named AnyTopic to be inserted into the current value at key /T, assuming that
 the current value is an object.

 <pre>
 insert AnyTopic at /T
 </pre>

 The following insert transformation would cause the whole value of the topic
 named AnyTopic to be inserted into the current value at key /T/MyKey,
 assuming that an object with the key T exists in the current value.

 <pre>
 insert AnyTopic at /T/MyKey
 </pre>

 The following insert transformation would cause the whole value of the topic
 named AnyTopic to be appended to the array at the key T in the current value.

 <pre>
 insert AnyTopic at /T/-
 </pre>

 The following insert transformation would cause the value at the key name
 within the topic named AnyTopic to be appended to the array at the key T in
 the current value.

 <pre>
 insert AnyTopic key /name at /T/-
 </pre>

 In the above examples no insertion would take place if the insertion value
 was not found, but a default value can be specified to insert into the
 current value in this case.

 <pre>
 insert AnyTopic at /T/- default "unknown"
 </pre>

 The path of the topic to insert from can be built from parts of the source
 topic path and/or scalar values within the current value. For example:

 <pre>
 insert AC/<path(1,1)>/<scalar(/myval)> at /T
 </pre>

 ### Options

 Options are specified after the mapping and any transformations. Any number
 of options may be specified but any particular option may only be specified
 once.

 #### Topic property mapping

 The {@link PTDiffusionTopicSpecification topic specification} of a reference topic is
 derived from the topic specification of the source topics. A reference topic
 has the same topic type as its source topic.

 The topic properties of a reference topic are derived from the source topic.
 Some topic properties can be tuned using the topic property mapping option.
 The following table describes the behavior for each topic property.

 <table>
    <tr>
        <th style="text-align:left;">Source topic property</th>
        <th>Reference topic specification default</th>
        <th>Can be set by topic property mapping?</th>
        <th>Notes</th>
    </tr>
    <tr>
        <th style="text-align:left;">`compressionPropertyKey`</th>
        <td>Copied from source topic specification</td>
        <td>Yes</td>
        <td></td>
    </tr>
    <tr>
        <th style="text-align:left;">`conflationPropertyKey`</th>
        <td>Copied from source topic specification</td>
        <td>Yes</td>
        <td></td>
    </tr>
    <tr>
        <th style="text-align:left;">`dontRetainValuePropertyKey`</th>
        <td>Copied from source topic specification</td>
        <td>Yes</td>
        <td></td>
    </tr>
    <tr>
        <th style="text-align:left;">`ownerPropertyKey`</th>
        <td>Not set</td>
        <td>No</td>
        <td></td>
    </tr>
    <tr>
        <th style="text-align:left;">`persistentPropertyKey`</th>
        <td>Not set</td>
        <td>No</td>
        <td>Reference topics are not persisted. Topic views are persisted, so a
            reference topic will be recreated on server restart if its source is
            persistent.</td>
    </tr>
    <tr>
        <th style="text-align:left;">`priorityPropertyKey`</th>
        <td>Copied from source topic specification</td>
        <td>Yes</td>
        <td></td>
    </tr>
    <tr>
        <th style="text-align:left;">`publishValuesOnlyPropertyKey`</th>
        <td>Copied from source topic specification</td>
        <td>Yes</td>
        <td></td>
    </tr>
    <tr>
        <th style="text-align:left;">`removalPropertyKey`</th>
        <td>Not set</td>
        <td>No</td>
        <td>Reference topics cannot be removed directly.</td>
    </tr>
    <tr>
        <th style="text-align:left;">`schemaPropertyKey`</th>
        <td>Copied from source topic specification</td>
        <td>No</td>
        <td>A recordV2 reference topic has the same
            schema as its source topic.</td>
    </tr>
    <tr>
        <th style="text-align:left;">`tidyOnSubscribePropertyKey`</th>
        <td>Copied from source topic specification</td>
        <td>Yes</td>
        <td></td>
    </tr>
    <tr>
        <th style="text-align:left;">`timeSeriesEventValueTypePropertyKey`</th>
        <td>Copied from source topic specification</td>
        <td>No</td>
        <td>A time series reference topic has the same
            value type as its source topic.</td>
    </tr>
    <tr>
        <th style="text-align:left;">`timeSeriesRetainedRangePropertyKey`</th>
        <td>Copied from source topic specification</td>
        <td>Yes, with restrictions</td>
        <td>A topic property mapping cannot increase the time series retained range
            by overriding the `TIME_SERIES_RETAINED_RANGE` property. The retained
            range of a reference time series topic will be constrained to be no greater
            than that of its source topic.</td>
    </tr>
    <tr>
        <th style="text-align:left;">`timeSeriesSubscriptionRangePropertyKey`</th>
        <td>Copied from source topic specification</td>
        <td>Yes</td>
        <td></td>
    </tr>
    <tr>
        <th style="text-align:left;">`validateValuesPropertyKey`</th>
        <td>Not set</td>
        <td>No</td>
        <td>A reference topic reflects updates to its source topic. It cannot reject
            updates.</td>
    </tr>
 </table>

 A topic property option begins with the keywords `with properties` and
 consists of a comma-separated list of topic property keys and values, each
 separated by a colon. For example, the following topic view specification
 maps all topics below the path `a` to reference topics below the
 path `b`, and disables both conflation and compression for the
 reference topics.

 <pre>
 map ?a// to b/<path(1)> with properties CONFLATION:off, COMPRESSION:false
 </pre>

 #### Topic value option

 By default, a reference topic's value is a copy of the source topic value, or
 part of the source value produced by an expand path mapping directive and/or
 modified by transformations. For {@link PTDiffusionTopicType#PTDiffusionTopicType_JSON JSON} source topics or {@link PTDiffusionTopicType#PTDiffusionTopicType_TimeSeries Time Series} source topics with a JSON event
 type, the value option can be applied to extract part of the resulting value
 (the latest value in the case of {@link PTDiffusionTopicType#PTDiffusionTopicType_TimeSeries time series} topics).

 A topic value option begins with the keyword `as` and is followed by a
 value directive. A value directive is delimited by angle brackets (`<`,
 `>`), and consists of the `value` keywords and a single JSON
 pointer parameter. The JSON pointer selects the part of the current value to
 copy.

 For example, given a current value of:

 <pre>
 {
     "account" : "1234",
     "balance" : { "amount" : 12.57, "currency" : "USD" }
 }
 </pre>

 and the value option `as <value(/balance)>`, the reference topic value
 will be:

 <pre>
 {
     "amount" : 12.57,
     "currency" : "USD"
 }
 </pre>

 Value mappings that follow expand directives and/or transformations apply to
 the current derived value and not the source topic value.

 Topic value mappings only alter the reference topic value; only the path
 mapping determines whether a reference topic should exist. If the topic value
 mapping's JSON pointer fails to select anything from the source topic value,
 the reference topic will have the JSON value `null`.

 Topic value mappings are often used with path value mappings to avoid repeating
 information in the path and the value. For example:

 <pre>
 map ?accounts// to balances/<scalar(/account)> as <value(/balance)>
 </pre>

 #### Throttle options

 The throttle option can be used to constrain the rate at which a reference
 topic is updated when its source topic is updated. The primary application of
 a throttle option is to restrict the number of updates sent to reference
 topic subscribers, reducing network utilization or the processing each
 subscriber must do. Throttling also restricts the rate at which client
 sessions can observe changes to reference topic values using the fetch API.

 The throttle option has the form
 <code>throttle to <em>X</em> updates every <em>period</em></code>, where
 <em>X</em> is a positive integer, and <em>period</em> is a positive integer
 followed by a time unit which is one of `seconds`,
 `minutes`, or `hours`.

 For example, the following topic view specification maps all topics below the
 path `a` to reference topics below the path `b`, but
 updates the value of each reference topic at most twice every five seconds:

 <pre>
 map ?a// to b/<path(1)> throttle to 2 updates every 5 seconds
 </pre>

 To improve readability, the throttle option allows `1 update` as
 an alternative to `1 updates`, and `every second` as an
 alternative to `every 1 seconds` (and so on, for other time
 units). For example, the following topic view specification maps all topics
 below the path `a` to reference topics below the path
 `b`, but updates the value of each reference topic at most once
 every hour:

 <pre>
 map ?a// to b/<path(1)> throttle to 1 update every minute
 </pre>

 The throttle option is only applied when a source topic is updated more
 frequently than the configured rate. If a source topic is updated less
 frequently, updates are passed on unconstrained. If the rate is exceeded, a
 reference topic will not be updated again until the configured period has
 expired. At this time, the reference topic will be updated based on the
 source topic updates that happened in the interim, and a single value will be
 published. Thus, the throttle option provides <em>topic-scoped
 conflation</em>.

 The throttle option is ignored for time series topics because time series
 updates do not support efficient conflation. Updates to source time series
 topics are passed on immediately to the corresponding reference topics,
 regardless of any throttle clause.

 #### Delay option

 The delay option causes a change to a view's source topic to be delayed by a
 fixed time before it is reflected in reference topics. Topic additions,
 updates, and removals are all delayed. Delays can range from one second to
 many days​.

 Such a publication delay is a useful way to devalue topic data so it can be
 given away to non-paying users​.

 The delay option has the form <code>delay by <em>duration</em></code>, where
 <em>duration</em> is a positive integer followed by a time unit which is one
 of <code>seconds</code>, <code>minutes</code>, or <code>hours</code>.

 For example, the following topic view specification maps all topics below the
 path <code>a</code> to reference topics below the path <code>b</code>, but
 changes to a source topic are delayed by five minutes before they are
 reflected in the corresponding reference topic.

 <pre>
 map ?a// to b/<path(1)> delay by 5 minutes
 </pre>

 Views with the delay option specified initially create reference topics in an
 unpublished state. The topics are published once the delay time has expired.
 A topic in the unpublished state prevents a lower priority topic view from
 creating a reference topic with the same path. Sessions with the rights to
 read the source topic can browse unpublished topics using the
 {@link PTDiffusionFetchRequest#withUnpublishedDelayedTopics withUnpublishedDelayedTopics} fetch request option.

 #### Separator option

 Views can use the scalar and expand directives in path mappings to extract
 text from the source value. By default, any `/` characters in the text
 are interpreted as path separators and will introduce extra levels in
 reference topic paths. If this is undesirable, the separator option can be
 used to replace any `/` characters produced by the <em>scalar</em> and <em>expand</em>
 directives with a constant string. The replacement can contain path
 separators but must have no empty path segments (`//`).

 Here is an example replacing all path separators with an alternate character:

 <pre>
 map ?a/path/ to b/<scalar(/x/y)> separator '\%'
 </pre>

 If the value at `/x/y` in the source topic was `foo/bar`, this would cause the
 reference topic to be created at <code>/b/foo\%bar</code> instead of
 <code>/b/foo/bar</code>

 #### Preserve topics option

 The default behavior for a topic view is that only the reference topics that
 can be derived from the current value of the source topic are maintained.
 This applies to views using directives that derive the path of the reference
 topic(s) from a value within the source topic (e.g. scalar or expand). For
 example if a view uses a scalar directive to determine the path of the
 reference topic and the source topic is updated such that the selected scalar
 value changes then the previously created reference topic will be removed and
 a new one created. Similarly an expand directive may create many reference
 topics from the source value but if the source is updated then only those
 reference topics that still have a corresponding value within the source
 value will be updated (or new ones added if not in the previous value),
 whilst others will be removed.

 There are situations where an application may not want reference topics to be
 removed because of source value changes. In such cases the 'preserve topics'
 option may be used to indicate that all reference topics created by a view
 should be retained (and updated by later updates that apply to it) until
 either the source topic or the creating view are removed.

 For example:
 <pre>
 map ?a/path/ to b/<expand()> preserve topics
 </pre>

 #### Topic type option

 The 'type' option can be used to specify the {@link PTDiffusionTopicType} of the target
 reference topic. If the current source value of type indicated by the source
 topic's type can be converted to the target type, a reference topic of the
 specified type will be created.

 For example:
 <pre>
 map ?a/ to b/<path(1)> type STRING
 </pre>

 The specified type must be one of the supported target types
 {@link PTDiffusionTopicType#PTDiffusionTopicType_String STRING},
 {@link PTDiffusionTopicType#PTDiffusionTopicType_Int64 INT64},
 {@link PTDiffusionTopicType#PTDiffusionTopicType_Double DOUBLE},
 {@link PTDiffusionTopicType#PTDiffusionTopicType_JSON JSON},
 {@link PTDiffusionTopicType#PTDiffusionTopicType_TimeSeries TIME_SERIES} or
 {@link PTDiffusionTopicType#PTDiffusionTopicType_Binary BINARY},
 case insensitive.

 The following table describes the supported conversions from the source topic
 type (the left column) to the supported target types. The number in brackets
 indicates a note at the foot of the table describing exactly how the
 conversion is processed. Where there is no number, no conversion is necessary
 and the derived source value is simply mapped to the target reference topic
 as if the <em>type</em> options was not specified. Where there is no entry for the
 source topic type in the left column, no conversion is supported and topics
 of unsupported types will not be processed by the topic view. An <em>x</em>
 indicates that the conversion is not supported.

 In all cases the value being processed will be the <em>current</em> value as derived
 from other mappings with the topic view (e.g. `expand`) which is not
 necessarily the value of the source topic.

 <table border=1>
    <tr>
        <th style="text-align:left;">Source topic</th>
        <th style="text-align:center;">{@link PTDiffusionTopicType#PTDiffusionTopicType_String STRING}</th>
        <th style="text-align:center;">{@link PTDiffusionTopicType#PTDiffusionTopicType_Int64 INT64}</th>
        <th style="text-align:center;">{@link PTDiffusionTopicType#PTDiffusionTopicType_Double DOUBLE}</th>
        <th style="text-align:center;">{@link PTDiffusionTopicType#PTDiffusionTopicType_JSON JSON}</th>
        <th style="text-align:center;">{@link PTDiffusionTopicType#PTDiffusionTopicType_TimeSeries TIME_SERIES}</th>
        <th style="text-align:center;">{@link PTDiffusionTopicType#PTDiffusionTopicType_Binary BINARY}</th>
    </tr>
    <tr>
        <th style="text-align:left;">{@link PTDiffusionTopicType#PTDiffusionTopicType_String STRING}</th>
        <td style="text-align:center;"></td>
        <td style="text-align:center;">(1)</td>
        <td style="text-align:center;">(1)</td>
        <td style="text-align:center;">(2)</td>
        <td style="text-align:center;">(3)</td>
        <td style="text-align:center;">x</td>
    </tr>
    <tr>
        <th style="text-align:left;">{@link PTDiffusionTopicType#PTDiffusionTopicType_Int64 INT64}</th>
        <td style="text-align:center;">(4)</td>
        <td style="text-align:center;"></td>
        <td style="text-align:center;">(5)</td>
        <td style="text-align:center;">(2)</td>
        <td style="text-align:center;">(3)</td>
        <td style="text-align:center;">x</td>
    </tr>
    <tr>
        <th style="text-align:left;">{@link PTDiffusionTopicType#PTDiffusionTopicType_Double DOUBLE}</th>
        <td style="text-align:center;">(4)</td>
        <td style="text-align:center;">(6)</td>
        <td style="text-align:center;"></td>
        <td style="text-align:center;">(2)</td>
        <td style="text-align:center;">(3)</td>
        <td style="text-align:center;">x</td>
    </tr>
    <tr>
        <th style="text-align:left;">{@link PTDiffusionTopicType#PTDiffusionTopicType_JSON JSON}</th>
        <td style="text-align:center;">(7)</td>
        <td style="text-align:center;">(7)</td>
        <td style="text-align:center;">(7)</td>
        <td style="text-align:center;"></td>
        <td style="text-align:center;">(3)</td>
        <td style="text-align:center;">x</td>
    </tr>
    <tr>
        <th style="text-align:left;">{@link PTDiffusionTopicType#PTDiffusionTopicType_TimeSeries TIME_SERIES}</th>
        <td style="text-align:center;">(8)</td>
        <td style="text-align:center;">(8)</td>
        <td style="text-align:center;">(8)</td>
        <td style="text-align:center;">(8)</td>
        <td style="text-align:center;"></td>
        <td style="text-align:center;">(9)</td>
    </tr>
    <tr>
        <th style="text-align:left;">{@link PTDiffusionTopicType#PTDiffusionTopicType_Binary BINARY}</th>
        <td style="text-align:center;">x</td>
        <td style="text-align:center;">x</td>
        <td style="text-align:center;">x</td>
        <td style="text-align:center;">x</td>
        <td style="text-align:center;">(9)</td>
        <td style="text-align:center;"></td>
    </tr>
 </table>

 Conversion notes:
 <ol>
    <li>{@link PTDiffusionTopicType#PTDiffusionTopicType_String STRING}
        to number conversions will only occur if
        the value of the string can be converted to the target number type. If the
        string cannot be converted then no reference topic will be created.
    <li>Primitive types to {@link PTDiffusionTopicType#PTDiffusionTopicType_JSON JSON}
        will result in a JSON topic containing just the scalar value.
    <li>Conversions to {@link PTDiffusionTopicType#PTDiffusionTopicType_TimeSeries TIME_SERIES}
        will result in a time series topic with an event type matching the source topic.
        Every update to the source topic will result in a new value being appended to the
        reference time series topic. It is not possible to convert to a time series
        topic with a different event type from the source topic.
    <li>Conversions from number types to
        {@link PTDiffusionTopicType#PTDiffusionTopicType_String STRING} will result in a
        simple string representation of the number in the reference topic value.
    <li>{@link PTDiffusionTopicType#PTDiffusionTopicType_Int64 INT64} to
        {@link PTDiffusionTopicType#PTDiffusionTopicType_Double DOUBLE}
        conversions perform a simple conversion. For example, `123` becomes `123.0`.
    <li>{@link PTDiffusionTopicType#PTDiffusionTopicType_Double DOUBLE} to
        {@link PTDiffusionTopicType#PTDiffusionTopicType_Int64 INT64}
        conversions perform rounding to the nearest integer value. For example, `12.51`
        becomes `13`.
    <li>{@link PTDiffusionTopicType#PTDiffusionTopicType_JSON JSON} to primitive
        type conversions only occur if the JSON value is a scalar which can be read
        as a string and converted to the target type. Currently, only string and
        integer scalar values can be read as
        a string (i.e. not doubles). The string representation of the value will be
        converted in the same way as specified for
        {@link PTDiffusionTopicType#PTDiffusionTopicType_String STRING} to other
        primitive types. If the JSON value is a structure or cannot be converted
        then no conversion takes place and no reference topic will be created.
    <li>The conversion of {@link PTDiffusionTopicType#PTDiffusionTopicType_TimeSeries TIME_SERIES}
        to other types follows the same rules as for conversion from the source
        topic type that matches the source time series topic's event value type.
        So if the time series event type is `double` then the conversion rules from
        source topic type {@link PTDiffusionTopicType#PTDiffusionTopicType_Double DOUBLE}
        to the target type will apply. Each value appended to the source time series
        topic will result in an update to the reference topic. If a failure to convert
        occurs at any point then the reference topic would be removed and only recreated
        if a value is appended that can be converted.
    <li>{@link PTDiffusionTopicType#PTDiffusionTopicType_Binary BINARY} to
        {@link PTDiffusionTopicType#PTDiffusionTopicType_TimeSeries TIME_SERIES},
        and vice-versa is supported in the same way as for other time series conversions.
 </ol>

 ### Escaping and quoting special characters

 Each part of a topic view expression has characters with special
 significance. Source topic clauses and path mapping clauses are delimited by
 white space. Directives in path and topic property mapping clauses are
 delimited by the `<` and `>` characters, and each directive
 parameter is terminated by `,` or `)`. Topic property mapping
 clauses are delimited by white space, and the `:` and `,`
 characters.

 Sometimes a topic view must refer to or generate topics with paths that
 containing special characters, or use a JSON pointer containing special
 characters. The escape sequence `\x` can be used to literally insert
 any character `x`, with a one exception: `\/` cannot be used in
 path fragments since the path delimiter `/` is always significant.

 Here is an example topic view expression containing escape sequences. It maps
 the topic path `a topic` a reference topic with the path
 `another topic`.

 <pre>
 map a\ topic to another\ topic
 </pre>

 Here is an example with a source value directive that uses the JSON pointer
 `/x()/y` to extract the target path from the source value. The
 `)` character in the JSON pointer must be escaped so it is not treated
 as the end of the parameter list.

 <pre>
 map ?a// to <scalar(/x(\)/y)>
 </pre>

 To insert `\`, the escape sequence `\\` must be used.

 There is no need to escape white space in JSON pointers directive parameters.
 However, white space is significant. For example, the following expressions
 have different topic value mapping clauses since the JSON pointer in the
 second expression is `"/x "`; that is, it has a trailing space:

 <pre>
 map a to b as <value(/x)>
 map a to b as <value(/x )>
 </pre>

 Instead of using escape sequences, white space characters can be included in
 source topic clauses and path mapping clauses using quotes. A clause is
 quoted by wrapping it in single quote (`'`) or double quote (`"`)
 characters. For example:

 <pre>
 map "a topic" to "another topic"
 </pre>

 Within a quoted clause, quotes of the same type must be escaped:

 <pre>
 map 'alice\'s topic' to 'bob\'s topic'
 </pre>

 For consistency, the values in topic property mapping clauses can be escaped
 or quoted. However, there is no need to do so because none of the valid
 values for the mappable properties contain special characters.

 ## Dealing with topic path conflicts

 Reference topics have a lower priority than normal topics created through the
 API, including replicas of normal topics created by topic replication or
 fan-out. A reference topic will only be created if no topic or reference topic
 is already bound to its derived topic path.

 Topic views have a precedence based on order of creation. If two topic views
 define mappings the same topic path, the earliest-created topic view will
 create a reference topic. If a topic view is updated, it retains its original
 precedence.

 ## Remote topic views

 A remote topic view is one that specifies another server as the location of
 the source topics using the <em>from</em> clause as shown in the example
 below:

 <pre>
 map ?a// from server1 to b/<path(1)>
 </pre>

 The server name `server1` in this example refers to the name of a
 remote server created.

 In this case, upon establishing a successful connection with the remote
 server indicated the topic view will create reference topics locally based
 upon the topics selected by the topic view's selector at the remote server.
 It is important to note that the selector <em>only</em> refers to topics that
 match it at the remote server and not on the local server and there is no
 reason why there could not be a source topic at the remote server that has
 the same path as an entirely different topic on the local server.

 More than one topic view can specify the same remote server.

 A remote server only makes a physical connection when it is in use, therefore
 the first topic view that specifies a remote server will cause it to
 establish a connection. Similarly, if the last topic view that uses a remote
 server is removed then the connection will be closed.

 It is not necessary for the named remote server definition to exist before
 creating the topic view, as if it does not then the topic view will simply
 remain dormant until the remote server is created and a successful connection
 to the server specified in its URL is established. Similarly, if a remote
 server that is in use by remote topic views is removed then all of the
 reference topics created by the topic views will be removed and the topic
 views will become dormant until the named remote server is created again or
 the views are changed to name a different remote server.

 If a remote topic view selects a
 {@link PTDiffusionTopicType#PTDiffusionTopicType_Routing routing} topic at
 the remote server then local mappings will only be performed if the routing
 topic mapping at the remote server is able to establish a mapping for the
 remote server connection. The mapping will be done as if from the resolved
 routing topic.

 The rules of precedence for remote topic views are the same as for other topic
 views. If the remote server for a remote topic view does not exist or does
 not have an established connection then the remote topic view is not evaluated
 (i.e. it is as if the source topics for the view did not exist), but if the
 remote server later connects then the view will be evaluated and rules of
 precedence will determine whether reference topic will replace those created
 by earlier views.

 ## Topic view persistence and replication

 Reference topics are neither replicated nor persisted. They are created and
 removed based on their source topics. However, topic views are replicated and
 persisted. A server that restarts will restore topic views during recovery.
 Each topic view will then create reference topics based on the source topics
 that have been recovered.

 The server records all changes to topic views in a persistent store. Topic
 views are restored if the server is started.

 If a server belongs to a cluster, topic views (and remote servers) will be
 replicated to each server in the cluster. Topic views are evaluated locally
 within a server. Replicated topic views that select non-replicated source
 topics can create different reference topics on each server in the cluster.
 When remote topic views are in use, each server in the cluster will make a
 connection to the specified remote server and will separately manage their
 remote topic views.

 A view with a delay clause uses temporary storage to record delayed events.
 If there is a high volume of updates, temporary per-server disk files will be
 used to save server memory​. The storage is per-server, and does not survive
 server restart. When a server is started, no data will be published by a view
 with a delay clause until the delay time has expired.

 ## Access control

 To list the topic views a session needs {@link PTDiffusionGlobalPermission#readTopicViews readTopicViews}
 permission.
 To create or remove a topic view a session needs
 {@link PTDiffusionGlobalPermission#modifyTopicViews modifyTopicViews}
 permission, {@link PTDiffusionPathPermission#selectTopic selectTopic} permission for the prefix of
 the source topic selector and {@link PTDiffusionPathPermission#modifyTopic modifyTopic} permission
 for the prefix of the path mapping.

 ## Accessing the feature

 The Topic Views feature for a session can be obtained from the session's
 {@link PTDiffusionSession#topicViews topicViews} property.

 @see PTDiffusionSession

 @since 6.3
 */
@interface PTDiffusionTopicViewsFeature : PTDiffusionFeature

/**
 Create a new named topic view.

 If a view with the same name already exists the new view will update the
 existing view.

 @param name The name of the view.

 @param specification The specification of the view using the DSL.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @param view the created topic view if the operation was successful.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.3
 */
-(void)createTopicViewWithName:(NSString *)name
                 specification:(NSString *)specification
             completionHandler:(void (^)(PTDiffusionTopicView * _Nullable view, NSError * _Nullable error))completionHandler;

/**
 List all the topic views that have been created.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `views` will contain a list of views sorted by their
 creation order. The completion handler will be called asynchronously on the
 main dispatch queue.

 @param views the topic views that have been created if the operation was successful.

 @exception NSInvalidArgumentException If completionHandler is `nil`.

 @since 6.3
 */
-(void)listTopicViewsWithCompletionHandler:(void (^)(NSArray<PTDiffusionTopicView *> * _Nullable views, NSError * _Nullable error))completionHandler;

/**
 Remove a named topic view if it exists.

 If the named view does not exist then the operation is considered successful
 and the completion handler is called accordingly.

 @param name The name of the view.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil`. The completion handler will be called asynchronously on
 the main dispatch queue.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.3
 */
-(void)removeTopicViewWithName:(NSString *)name
             completionHandler:(void (^)(NSError * _Nullable error))completionHandler;


/**
 Get a named Topic View.

 @param name the name of the view.

 @param completionHandler Block to be called asynchronously on success or
 failure. If the operation was successful, the `error` argument passed to the
 block will be `nil` and `view` will contain the named view if it exists.
 The completion handler will be called asynchronously on the main dispatch queue.

 @exception NSInvalidArgumentException If any argument is `nil`.

 @since 6.8
 */
-(void)getTopicViewWithName:(NSString *)name
          completionHandler:(void (^)(PTDiffusionTopicView * _Nullable view, NSError * _Nullable error))completionHandler;


@end

NS_ASSUME_NONNULL_END
