# YogaBase_1.0
Qt application focused on improving yoga practice

This "All-In-One" application represents base asanas used in yoga practice. The main goal is to help users who are interested in yoga to get more information about each asana, to comprehence benefits and restricts of each pose, to see its real execution represented by photo. At this moment there are 48 asanas that have different value of difficulty and usefullness.

App is made as a bound of 4 main tabs. Each tab represents its own feature.
The first tab shows a table contains all asanas' information. 
The second tab contains detail information about separate asana, chosen by user. 
The another one is used for searching in asanas' database, represented by xml-file. 
And the last one represents admin-page where authorized user can add a new asana into DB and update it in real-time mode.
At the starting of application user can choise the language used in programm. After the splash screen will be shown.    
Here is a catagorized list of app's features.

1. COMMON FEATURES:

	- representing all asanas' information in different style: 
		-- table-view 
		-- card-styled 
		-- detail-mode
	- categorizing asanas' by features:
		-- origin name (Hindi-pronunciation)
		-- transcripted name
		-- pose type based on body support 
		-- detail description of asana
		-- represented photo by each asana
		-- 32 options catagorized into 5 blocks represent focusing on separate body system (improving system or liquidate negative influence):
			--- concrete organ (f.e, spleen)
			--- body part (f.e, spine)
			--- body system (f.e, vestibular apparatus)
			--- anti / boost (f.e, improve endurance or liquidate stress)
			--- disease (f.e, scoliosis)
	- using multi-language system (2 languages in current version)
	- filtering asanas by described features, including grouping, sorting, searching
	- adding new asanas into database
	- updating database in real-time mode
	- uisng RT-interconnection between different widgets
	- using bitset logic to improve memory using
	- providing creative and friendliness dark-mode UI, using uniform "orange-tech" style in each widget 
	- using CG-effects
	- using splash screen
	- improving UI by using two types of asanas' images
	- providing tip's system
	- separating data (compiled and real-time using resources) 

2. SEPARATE TAB FEATURES:

	2.1. MAIN WINDOW:
		- representing side tabbar menu for quick access to separate tab
		- showing current tab widget area
		- showing current app's language
		- styled showing of active tabbar item
		- using styled tabbar navigation within hover-effects
		- scalable widget areas

	2.2. ASANA TABLE TAB:
		- table view of total asanas' information
		- sorting asanas by each column that helps to see required asanas by sorting criteria
		- opening full-mode image by image-cell clicking in current window as a separate widget with the forward closing provided by repeated click 
		- adjusting column's width and row's height by its content clicking on the header separate area
		- stable viewing of main column and row
		- showing small image in header column cells that indicates the asana's concrete benefit
		- providing protection of changes in table by entering into cells within keyboard or mouse
		- using stable highlights for quick watching on enable asanas' benefits
		- using dynamic highlights in picked cell that helps user to concentrate onto current asana's information
		- using stylized scrollbars to contain invisible columns 
		- using different cursor-changing effects onto cells as hints
		- gradient-styled dark columns

	2.3. ASANA DETAIL TAB:
		- representing total information about currently loaded asana
		- separating each part of information into different blocks
		- providing carousel-styled navigation system to quick asana change in bottom part of widget
		- navigating asanas in 3 modes:
			-- forward, clicking on right arrow
			-- backward, clicking on left arrow
			-- moving to picked asana, clicking on responding asana's circle
		- quick information updating into current window
		- showing asana's photo as a background image and as a separate block to improve user's notion about asana
		- representing asana's benefits in one leftside area as a block of hexagon-styled elements, each one of contains a feature's image; this way it's possible to show all 32 possible asana's features in one small area and select the enable
		- using tip-system for hex-styled elements 
		- using stylized highlighting of enable (active) asana's benefits
		- representing asana's Hindi-version name, transcripted name and detail description in separate text-blocks  
		- dynamicaly updating whole db and style information        
		- providing quick programm changing of carousel-circle count
		- using hover-effects onto circles as hints 	
		- using different background-styles in each layers

	2.4. ASANA SEARCH TAB:
		- providing asanas' full search-system tab using next criterias:
			-- separate anasa benefit (32 options, can combine in any set with each other and other types of criteria)
			-- keywords related to asana's description, base name or transcripted name, presented as a text input field  
			-- pose type presented as a dropdown list
			-- clearing search inputs by clean button 
		- presenting all required (filtered) asanas in a separate table-area, each asana is shown as card-look widget contains base information about asana
		- filtering asanas by hiding not compatible cards and showing required at the beginning of the card-table  
		- presenting count of asana's benefits to get quick attention of user
		- providing button in each card, that moves user forward to "DETAIL ASANA" tab by click, opening directly required asana to get more information about it  
		- using scrollbar to contain non-shown cards  
		- providing quick programm changing of card-column count
		- using stylized scrollbars to contain invisible cards
	2.5. ASANA CREATION TAB:
		- providing special form to complete full information of new asana to insert into db
		- protecting of empty or incorrect inputs
		- trimming strings
		- using image-filtering dialogs to get new asana's images
		- dividing form into different content blocks 
		- using clearing button resets all inputs
		- providing simple authorization system proposes user to input admin-password to confirm inserting
		- containing admin-password in a separate file
		- copying and renaming of user's picked image-files

3. USED PROGRAMMING TECHNICS AND FEATURES:
	- differrent Qt Widgets/Layouts with providing methods
	- Qt signals and slots, including lambda-version
	- Qt events, including filters
	- Qt forms
	- Qt debug system
	- styling, including .qml-files and provided classes for implementing graphical effects
	- resources, including .qrc-files 
	- translations including .ts-files and Qt Linguist
	- xml-files as a DB-sources including provided classes for implementing XML-logic  
	- std containers
	- std algorithms
	- std::function
	- lambdas
	- bit manipulations
	- AI to make such nice photos

Here is a plan-list of future app's improvements will be implicated in versions 1.1 and 1.2:
	- adding more asanas
	- supporting more languages
	- extending asanas' information base
	- implementing OpenGL-technics, f.e, adding asana's trigger points to main photo on "DETAIL"-tab with dynamical updating to improve user's experience and deeply understand the nuances of current asana
	- adding video information block
	- extending desease-base information
	- adding asana-courses, based on concrete desease 
	- improving search-system, using hash-table of all existed words and word-combinations in DB
	- adding parsing-system using attributes to indicate triggers in asana's description
	- filtering asanas' cards by count of benefits    
	- more comprehensive interconnection between widgets, including asanas' information blocks 
	- increasing carousel-moving and DB-updating speed
	- implementing socket-logic to:
		-- improve creation-form by getting multi-lang information, using AI-servers 
		-- implement AI to make png-version asana's photo autimaticaly using user's one provided
	- implementing switching app's language in run-time
	- fixing some UI-bugs
	- perhaps, adding functionality to add new asana's options (benefits)
	- perhaps, making mobile version

Thanks!
