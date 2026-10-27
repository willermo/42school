# ft_transcendence - Web-Based Pong Game Platform

## Table of Contents

1. [Introduction](#introduction)
2. [Project Constraints](#project-constraints)
3. [Makefile Structure](#makefile-structure)
4. [Docker Containerization Strategy](#docker-containerization-strategy)
5. [Project Goals and Webapp Usage](#project-goals-and-webapp-usage)
6. [Playable Games](#playable-games)
7. [Match Modes](#match-modes)
8. [Tournament System](#tournament-system)
9. [User Security Management](#user-security-management)
10. [Session Monitoring System](#session-monitoring-system)
11. [Two-Factor Authentication (2FA)](#two-factor-authentication-2fa)
12. [Google Login Integration](#google-login-integration)
13. [Dark/Light Mode](#darklight-mode)
14. [Profile Customizations](#profile-customizations)
15. [GDPR Compliance](#gdpr-compliance)
16. [Frontend Architecture](#frontend-architecture)
17. [Backend Architecture](#backend-architecture)
18. [SQLite3 Database Management](#sqlite3-database-management)
19. [TypeScript and Vite Configuration](#typescript-and-vite-configuration)

## Introduction

ft_transcendence is a comprehensive web-based gaming platform centered around the classic Pong game, developed as part of the 42 School curriculum. This project demonstrates modern web development practices by implementing a full-stack application with real-time multiplayer capabilities, tournament systems, and advanced security features.

The platform provides users with an engaging gaming experience while showcasing technical proficiency in areas such as:
- Custom frontend framework development (minireact)
- Real-time multiplayer gaming
- Advanced authentication and security systems
- Tournament management
- GDPR-compliant user data handling
- Docker containerization
- Modern TypeScript development

## Project Constraints

This didactical project was developed under specific constraints mandated by the 42 School curriculum:

### Technology Requirements
- **Frontend**: Must use TypeScript as the primary language
- **Backend**: Fastify with Node.js (implemented via module selection)
- **Database**: SQLite (implemented via module selection)
- **Containerization**: Docker is mandatory for deployment
- **Architecture**: Single-page application (SPA) architecture required
- **Browser Compatibility**: Must ensure Mozilla Firefox compatibility

### Security Requirements
- All passwords must be hashed using strong algorithms (bcrypt)
- Protection against XSS (Cross-Site Scripting) attacks
- Protection against SQL injection attacks
- HTTPS connections required for all communications
- Comprehensive input validation on all user inputs
- Credentials must be stored in environment files (excluded from version control)

### Module System
The project requires implementation of at least 7 major modules (or equivalent combinations) from categories including:
- Web framework modules
- User Management modules
- Gameplay Enhancement modules
- AI modules
- Cybersecurity modules
- DevOps modules
- Graphics modules
- Accessibility modules
- Server-Side Pong modules

### Development Approach
- Progressive implementation: mandatory requirements first, then modules
- Step-by-step development to facilitate learning
- Thorough testing at each development stage
- Comprehensive documentation throughout the process

## Makefile Structure

The project includes a comprehensive Makefile that manages both development and production environments through Docker Compose. The Makefile provides the following key functionalities:

### Environment Management
```bash
# Development environment (https://localhost:4433)
make start-dev     # Start development containers
make stop-dev      # Stop development containers
make build-dev     # Build development images
make logs-dev      # View development logs

# Production environment (https://localhost:4443)
make start-prod    # Start production containers
make stop-prod     # Stop production containers
make build-prod    # Build production images
make logs-prod     # View production logs

# Combined operations
make start-both    # Start both environments
make stop-both     # Stop both environments
```

### Shell Access
```bash
# Development shell access
make shell-backend-dev   # Access backend container shell
make shell-frontend-dev  # Access frontend container shell
make shell-nginx-dev     # Access nginx container shell

# Production shell access
make shell-backend-prod  # Access backend container shell
make shell-frontend-prod # Access frontend container shell
make shell-nginx-prod    # Access nginx container shell

# Aliases
make shell-dev     # Alias for backend development shell
make shell-prod    # Alias for backend production shell
```

### Certificate Management
```bash
make certs         # Generate self-signed SSL certificates
make nginx-certs   # Generate nginx-specific certificates
```

### Testing and Maintenance
```bash
make test-permissions      # Test container user permissions
make test-permissions-dev  # Test development container permissions
make test-permissions-prod # Test production container permissions
make test-file-ownership-dev # Test file ownership in mounted volumes
make test-flow            # Complete test flow (prune, build, start, test)
make prune                # Clean up containers, networks, and images
```

### UID/GID Management
The Makefile automatically exports the host user's UID and GID to prevent permission issues with Docker bind mounts:
```makefile
export UID := $(shell id -u)
export GID := $(shell id -g)
```

## Docker Containerization Strategy

The project implements a sophisticated multi-environment Docker strategy with separate configurations for development and production.

### Development Environment (`docker-compose.dev.yml`)

**Architecture Overview:**
- **Backend Container**: Node.js development server with hot reload
- **Frontend Container**: Vite development server with HMR
- **Nginx Container**: Reverse proxy and SSL termination

**Key Features:**
- Bind mounts for real-time code changes
- Hot Module Replacement (HMR) for instant updates
- Health checks for service dependencies
- Automatic certificate generation
- Development-specific environment variables

**Service Configuration:**
```yaml
backend:
  - Port: Internal 3000 (not exposed)
  - Command: npm run migrate:latest && npm run dev
  - Volumes: ./backend:/app (bind mount)
  - Health check: curl -kf https://localhost:3000/api/health

frontend:
  - Port: 5173 (exposed for direct access)
  - Command: npm run dev
  - Volumes: ./frontend:/app (bind mount)
  - Health check: curl -kf https://localhost:5173/

nginx:
  - Port: 4433 (HTTPS)
  - Serves as reverse proxy
  - SSL certificate management
```

### Production Environment (`docker-compose.prod.yml`)

**Architecture Overview:**
- **Backend Container**: Optimized Node.js production server
- **Frontend Container**: Build-only container (exits after building)
- **Nginx Container**: Serves static files and proxies API requests
- **Volume Permissions Container**: Manages file ownership

**Key Features:**
- Named volumes for data persistence
- Multi-stage builds for optimization
- Non-root user execution for security
- Automatic SSL certificate generation
- Production-optimized configurations

**Service Configuration:**
```yaml
backend:
  - User: node (non-root)
  - Command: npm run migrate:latest:prod && npm run start
  - Volumes: Named volumes for data persistence
  - No exposed ports (internal only)

frontend:
  - Build-only container
  - Outputs to shared volume
  - Exits after successful build

nginx:
  - Port: 4443 (HTTPS)
  - Serves static frontend files
  - Proxies API requests to backend
  - Custom Dockerfile with SSL setup
```

### Security Considerations
- All containers run as non-root users in production
- SSL/TLS encryption for all communications
- Proper file permissions management
- Network isolation through Docker networks
- Health checks for service reliability

## Project Goals and Webapp Usage

### Primary Goals

**Educational Objectives:**
- Demonstrate mastery of modern web development technologies
- Implement real-time multiplayer gaming capabilities
- Showcase advanced security practices
- Create a scalable and maintainable codebase
- Apply DevOps practices with containerization

**Technical Achievements:**
- Custom React-like framework (minireact) development
- Real-time WebSocket communication for multiplayer games
- JWT-based authentication with refresh token rotation
- GDPR-compliant user data management
- Tournament bracket system implementation
- Advanced security features (2FA, session monitoring)

### Webapp Usage and Workflow

**User Journey:**
1. **Registration/Login**: Users can register with email/password or use Google OAuth
2. **Profile Setup**: Complete profile with display name, avatar, and optional 2FA
3. **Game Selection**: Choose from Pong, Tic-Tac-Toe, or Connect Four
4. **Match Types**: Play casual games, ranked matches, or join tournaments
5. **Tournament Participation**: Register for tournaments and compete in brackets
6. **Profile Management**: Update settings, view match history, manage security

**Key Features:**
- **Responsive Design**: Works across desktop and mobile devices
- **Real-time Updates**: Live game states and tournament progress
- **Social Features**: Friend systems and match history
- **Accessibility**: Keyboard navigation and screen reader support
- **Internationalization**: Multi-language support capability

## Playable Games

The platform features three distinct games, each with unique gameplay mechanics and strategic depth:

### 1. Pong (Primary Game)
**Description:** The classic arcade game that started it all, faithfully recreated with modern enhancements.

**Features:**
- **Real-time Multiplayer**: Smooth 60 FPS gameplay with WebSocket synchronization
- **AI Opponents**: Multiple difficulty levels for single-player practice
- **Power-ups**: Optional game modifiers for enhanced gameplay
- **Customizable Settings**: Paddle speed, ball speed, and game duration options
- **Tournament Support**: Full integration with bracket tournaments

**Technical Implementation:**
- Canvas-based rendering for smooth animations
- Client-side prediction with server reconciliation
- Collision detection with precise physics simulation
- Spectator mode for tournament viewing

### 2. Tic-Tac-Toe
**Description:** The timeless strategy game with a modern interface and tournament capabilities.

**Features:**
- **Turn-based Gameplay**: Strategic thinking with time limits
- **AI Opponents**: Minimax algorithm implementation with multiple difficulties
- **Tournament Integration**: Single-elimination bracket support
- **Visual Enhancements**: Smooth animations and win condition highlighting

**Technical Implementation:**
- State-based game logic with move validation
- Minimax AI with alpha-beta pruning
- Real-time move synchronization
- Win condition detection and animation

### 3. Connect Four
**Description:** The classic connection game with gravity-based piece dropping.

**Features:**
- **Physics Simulation**: Realistic piece dropping with gravity
- **Strategic Depth**: Multiple winning patterns and blocking strategies
- **AI Integration**: Intelligent computer opponents
- **Visual Polish**: Smooth animations and piece highlighting

**Technical Implementation:**
- Grid-based game state management
- Gravity simulation for piece dropping
- Pattern matching for win detection
- Optimized AI using game tree search

## Match Modes

The platform supports three match types as defined in the codebase:

### Match Types

**From `frontend/src/types/games.ts` and `backend/src/types/games.ts`:**
```typescript
export type MatchType = "skirmish" | "ranked" | "tournament";
```

**1. Skirmish Mode**
- Casual play mode available in game settings
- Default configurations exist for all game types:
  - `pong1v1SkirmishDefault`
  - `pong2v2SkirmishDefault` 
  - `connectFourSkirmishDefault`
  - `ticTacToeSkirmishDefault`
- Can include AI opponents in some configurations

**2. Ranked Mode**
- Competitive match type (excluded from some match settings)
- Used in match creation and game configuration

**3. Tournament Mode**
- Used specifically for tournament matches
- Integrated with the tournament system

### Tournament Mode (Organized Competition)
**Purpose:** Structured competitive events using round-robin format.

**Tournament Format:**
- **Round Robin Only**: All participants play against each other
- **Game Types**: Supports Pong, Tic-Tac-Toe, and Connect Four
- **Ladder System**: Points-based ranking with wins/losses tracking

**Features:**
- Tournament creation and management
- Participant registration and tracking
- Automatic round-robin match generation
- Real-time ladder/ranking updates
- Tournament status tracking (pending, active, completed, cancelled)

## Tournament System

The tournament system implements a round-robin format where all participants play against each other.

### Tournament Structure

**Database Schema (from migrations):**
```sql
tournaments:
  - id: Primary key
  - name: Tournament name
  - gameType: Game type (pong, tic_tac_toe, connect4)
  - gameMode: Game mode (1v1, 2v2)
  - status: Tournament status (pending, active, completed, cancelled)
  - createdBy: User ID who created the tournament
  - winnerId: Winner user ID (nullable)
  - createdAt: Creation timestamp
  - startedAt: Start timestamp (nullable)
  - endedAt: End timestamp (nullable)
  - metadata: JSON metadata (nullable)
```

**Participant Management:**
```sql
tournament_participants:
  - id: Primary key
  - tournamentId: Foreign key to tournaments
  - userId: Foreign key to users
  - joinedAt: Registration timestamp
```

### Tournament Implementation

**Round-Robin Match Generation:**
The system uses a round-robin algorithm to generate matches between all participants:

```typescript
// From backend/src/types/tournament.ts
export function generateRoundRobinMatches(participantIds: number[]): Array<[number, number]> {
  const matches: Array<[number, number]> = [];
  
  for (let i = 0; i < participantIds.length; i++) {
    for (let j = i + 1; j < participantIds.length; j++) {
      matches.push([participantIds[i], participantIds[j]]);
    }
  }
  
  return matches;
}
```

**Ladder System:**
Tournaments use a points-based ladder system:

```typescript
// Tournament ladder entry structure
interface TournamentLadderEntry {
  userId: number;
  displayName: string;
  avatarFilename?: string;
  wins: number;
  losses: number;
  points: number;
  rank: number;
}
```

### Tournament Lifecycle

**1. Creation Phase:**
- Users can create tournaments with name and game type selection
- Tournament starts in "pending" status
- Creator becomes the tournament administrator

**2. Registration Phase:**
- Users can join pending tournaments
- Participant list is tracked in tournament_participants table
- No maximum participant limit enforced

**3. Active Phase:**
- Tournament creator can start the tournament
- System generates round-robin matches for all participants
- Tournament status changes to "active"
- Matches are created and can be played

**4. Completion:**
- Tournament can be marked as completed
- Final ladder standings are calculated
- No automated winner announcement or prize system

## User Security Management

The platform implements a comprehensive security framework designed to protect user data and prevent common web vulnerabilities.

### JWT Token System

**Access Tokens:**
- **Purpose**: Short-lived tokens for API authentication
- **Lifetime**: 15 minutes
- **Storage**: HTTP-only cookies for web security
- **Claims**: User ID, role, permissions, issued/expiry times
- **Algorithm**: HS256 with rotating secrets

**Refresh Tokens:**
- **Purpose**: Long-lived tokens for access token renewal
- **Lifetime**: 7 days (configurable)
- **Storage**: Secure HTTP-only cookies with SameSite=Strict
- **Rotation**: New refresh token issued with each use
- **Revocation**: Database-tracked for immediate invalidation

**Token Implementation:**
```typescript
// JWT payload structure
interface JWTPayload {
  sub: string;        // User ID
  email: string;      // User email
  role: 'user' | 'admin';
  iat: number;        // Issued at
  exp: number;        // Expires at
  jti: string;        // JWT ID for tracking
}
```

### CSRF Protection

**Implementation Strategy:**
- **Double Submit Cookie Pattern**: CSRF token in both cookie and header
- **SameSite Cookies**: Strict SameSite policy for all authentication cookies
- **Origin Validation**: Server validates request origin headers
- **Custom Headers**: Required custom headers for state-changing requests

**CSRF Token Lifecycle:**
1. Generated on login with cryptographically secure random values
2. Stored in HTTP-only cookie and provided to client
3. Client includes token in X-CSRF-Token header
4. Server validates token match on all state-changing requests
5. Token rotation on sensitive operations

### Refresh Token Management

**Database Schema:**
```sql
refresh_tokens:
  - id: Primary key
  - user_id: Foreign key to users
  - token_hash: SHA-256 hash of refresh token
  - expires_at: Token expiration timestamp
  - created_at: Token creation time
  - last_used: Last usage timestamp
  - revoked: Boolean revocation status
  - device_info: User agent and device fingerprint
```

**Security Features:**
- **Token Rotation**: New refresh token issued on each use
- **Automatic Cleanup**: Expired tokens removed via scheduled jobs
- **Device Tracking**: Multiple device support with individual token management
- **Immediate Revocation**: Real-time token invalidation capability
- **Suspicious Activity Detection**: Automatic revocation on anomalous usage patterns

### Password Security

**Hashing Algorithm:**
- **bcrypt**: Industry-standard password hashing
- **Salt Rounds**: 12 rounds (configurable via environment)
- **Automatic Salt Generation**: Unique salt per password
- **Timing Attack Protection**: Constant-time comparison operations

**Password Policies:**
- Minimum 8 characters length
- Must contain uppercase and lowercase letters
- Must contain at least one number
- Must contain at least one special character
- Password history prevention (last 5 passwords)
- Account lockout after 5 failed attempts

- **Incident Response**: Tools for investigating security incidents

## Two-Factor Authentication (2FA)

The platform implements TOTP (Time-based One-Time Password) 2FA for enhanced account security.

### 2FA Implementation

**Technology Stack:**
- **TOTP Algorithm**: RFC 6238 compliant implementation
- **Library**: otplib for token generation and validation
- **QR Code Generation**: qrcode library for setup QR codes
- **Backup Codes**: Cryptographically secure recovery codes

**Setup Process:**
1. **Initiation**: User enables 2FA in profile settings
2. **Secret Generation**: Server generates unique TOTP secret
3. **QR Code Display**: Secret encoded in QR code for authenticator app
4. **Verification**: User enters TOTP code to confirm setup
5. **Backup Codes**: System generates 10 single-use recovery codes
6. **Activation**: 2FA becomes mandatory for future logins

### TOTP Configuration

**Technical Parameters:**
```typescript
const totpConfig = {
  algorithm: 'SHA1',
  digits: 6,
  period: 30,        // 30-second time window
  window: 1,         // Allow 1 time step tolerance
  encoding: 'base32'
};
```

**Security Features:**
- **Time Window Validation**: 30-second validity periods
- **Clock Skew Tolerance**: ±30 seconds for time synchronization issues
- **Rate Limiting**: Maximum 3 attempts per time window
- **Replay Attack Prevention**: Used tokens tracked and rejected
- **Secret Rotation**: Ability to regenerate TOTP secrets

### Backup and Recovery

**Recovery Codes:**
- **Generation**: 10 unique 8-character alphanumeric codes
- **Usage**: Single-use codes for account recovery
- **Storage**: Hashed in database (bcrypt)
- **Display**: Shown only once during 2FA setup
- **Regeneration**: New codes generated when requested

**Account Recovery Process:**
1. User attempts login without access to authenticator
2. System prompts for recovery code
3. Recovery code validated and consumed
4. User gains temporary access to disable/reconfigure 2FA
5. Security notification sent to user email

## Google Login Integration

The platform supports Google OAuth 2.0 integration for seamless user authentication.

### OAuth 2.0 Implementation

**Google OAuth Configuration:**
```typescript
const googleOAuthConfig = {
  clientId: process.env.GOOGLE_CLIENT_ID,
  clientSecret: process.env.GOOGLE_CLIENT_SECRET,
  redirectUri: process.env.GOOGLE_REDIRECT_URI,
  scopes: ['openid', 'email', 'profile']
};
```

**Authentication Flow:**
1. **Initiation**: User clicks "Sign in with Google" button
2. **Redirect**: Browser redirects to Google OAuth consent screen
3. **Authorization**: User grants permissions to the application
4. **Callback**: Google redirects back with authorization code
5. **Token Exchange**: Server exchanges code for access token
6. **Profile Retrieval**: Server fetches user profile from Google API
7. **Account Linking**: System creates or links existing user account
8. **Session Creation**: Standard JWT session tokens generated

### Security Considerations

**State Parameter Validation:**
- Cryptographically secure state parameter generation
- State validation to prevent CSRF attacks
- Time-limited state tokens (5-minute expiry)

**Token Handling:**
- Google access tokens never stored permanently
- Immediate profile data extraction and token disposal
- No long-term Google token storage

**Account Linking Logic:**
```typescript
async function handleGoogleCallback(authCode: string, state: string) {
  // Validate state parameter
  await validateOAuthState(state);
  
  // Exchange code for tokens
  const tokens = await exchangeCodeForTokens(authCode);
  
  // Fetch user profile
  const profile = await fetchGoogleProfile(tokens.access_token);
  
  // Find or create user account
  let user = await findUserByEmail(profile.email);
  if (!user) {
    user = await createUserFromGoogleProfile(profile);
  } else {
    await linkGoogleAccount(user.id, profile.sub);
  }
  
  // Create application session
  return await createUserSession(user);
}
```

## Dark/Light Mode

The platform includes a comprehensive theming system supporting both dark and light modes with user preference persistence.

### Theme Implementation

**CSS Custom Properties:**
The theming system uses CSS custom properties (CSS variables) for dynamic color switching:

```css
:root {
  /* Light mode (default) */
  --bg-primary: #ffffff;
  --bg-secondary: #f8f9fa;
  --text-primary: #212529;
  --text-secondary: #6c757d;
  --border-color: #dee2e6;
  --accent-color: #007bff;
}

[data-theme="dark"] {
  /* Dark mode overrides */
  --bg-primary: #1a1a1a;
  --bg-secondary: #2d2d2d;
  --text-primary: #ffffff;
  --text-secondary: #b0b0b0;
  --border-color: #404040;
  --accent-color: #4dabf7;
}
```

**Tailwind CSS Integration:**
Custom Tailwind configuration extends the theme system:

```typescript
// tailwind.config.ts
module.exports = {
  darkMode: 'class',
  theme: {
    extend: {
      colors: {
        primary: 'var(--bg-primary)',
        secondary: 'var(--bg-secondary)',
        'text-primary': 'var(--text-primary)',
        'text-secondary': 'var(--text-secondary)',
      }
    }
  }
}
```

### User Experience Features

**Smooth Transitions:**
All theme changes include smooth CSS transitions for a polished user experience:

```css
* {
  transition: background-color 0.3s ease, color 0.3s ease, border-color 0.3s ease;
}
```

**System Integration:**
- Automatic detection of system dark/light mode preference
- Respect for user's OS-level theme settings
- Persistence of manual theme selection across sessions
- Real-time updates when system preference changes

**Accessibility Considerations:**
- High contrast ratios maintained in both themes
- Respect for `prefers-reduced-motion` media query
- Keyboard navigation support for theme toggle
- Screen reader announcements for theme changes

## Profile Customizations

The platform provides comprehensive profile customization options allowing users to personalize their gaming experience.

### Display Name Management

**Features:**
- **Unique Display Names**: System-wide uniqueness enforcement
- **Character Limits**: 3-30 characters with validation
- **Special Characters**: Alphanumeric, spaces, hyphens, and underscores allowed
- **Profanity Filtering**: Automated content moderation
- **Change Frequency**: Limit of one change per 30 days to prevent abuse

### Avatar System

**Avatar Options:**
- **File Upload**: Support for JPEG, PNG, WebP formats
- **Size Limits**: Maximum 5MB file size
- **Dimensions**: Automatic resizing to 256x256 pixels
- **Default Avatars**: Collection of generated default avatars
- **Gravatar Integration**: Optional Gravatar support

### Security Settings

**Available Options:**
- **2FA Management**: Enable/disable two-factor authentication
- **Password Changes**: Secure password update process
- **Session Management**: View and terminate active sessions
- **Account Deletion**: Complete account removal with data purging

## GDPR Compliance

The platform is fully compliant with the General Data Protection Regulation (GDPR) and implements comprehensive data protection measures.

### Data Protection Principles

**Lawfulness, Fairness, and Transparency:**
- Clear privacy policy explaining data collection and usage
- Explicit consent mechanisms for all data processing
- Transparent communication about data handling practices

**Purpose Limitation:**
- Data collected only for specified, legitimate purposes
- No secondary use of data without additional consent
- Clear documentation of processing purposes

**Data Minimization:**
- Collection limited to necessary data only
- Regular review and deletion of unnecessary data
- Opt-in approach for non-essential features

**Accuracy:**
- User-controlled profile information updates
- Regular data validation and correction mechanisms
- Automated cleanup of outdated information

**Storage Limitation:**
- Defined retention periods for different data types
- Automatic deletion of expired data
- User-initiated data deletion capabilities

**Integrity and Confidentiality:**
- End-to-end encryption for sensitive data
- Secure data transmission (HTTPS)
- Access controls and audit logging

### User Rights Implementation

**Right to Access:**
- User dashboard showing all collected data
- Data export functionality in machine-readable format
- Complete transparency about data processing

**Right to Rectification:**
- Self-service profile editing capabilities
- Data correction request mechanisms
- Prompt response to rectification requests

**Right to Erasure ("Right to be Forgotten"):**
- Complete account deletion functionality
- Cascading deletion of associated data
- Permanent removal from all systems and backups

**Right to Data Portability:**
- JSON export of all user data
- Standardized data formats for easy migration
- API endpoints for automated data retrieval

**Right to Object:**
- Granular consent management
- Opt-out mechanisms for marketing communications
- Processing objection handling procedures

### Technical Implementation

**Consent Management:**
```sql
user_consents:
  - user_id: Foreign key to users
  - consent_type: Type of consent (marketing, analytics, etc.)
  - granted: Boolean consent status
  - granted_at: Timestamp of consent
  - withdrawn_at: Timestamp of withdrawal (if applicable)
  - ip_address: IP address when consent was given
  - user_agent: Browser information
```

**Data Retention Policies:**
- User accounts: Retained until deletion request
- Session data: 90 days after last activity
- Game statistics: 2 years for competitive integrity
- Audit logs: 7 years for security compliance
- Marketing data: Until consent withdrawal

**Privacy by Design:**
- Default privacy-friendly settings
- Minimal data collection by default
- Regular privacy impact assessments
- Built-in data protection measures

## Frontend Architecture

The frontend is built using a custom React-like framework called **minireact**, providing a lightweight yet powerful foundation for the user interface.

### Minireact Framework

**Core Features:**
- **JSX/TSX Support**: Full JSX syntax support with TypeScript integration
- **Functional Components**: Component-based architecture with props and children
- **Custom Hooks**: useState, useEffect, useRef, useCallback, and custom hooks
- **Virtual DOM**: Efficient rendering with diff algorithm
- **Event System**: Synthetic event system with delegation
- **Routing**: Built-in SPA routing with navigation context
- **Context API**: State sharing between components

**Architecture Benefits:**
- **Lightweight**: Minimal bundle size compared to full React
- **Educational**: Complete understanding of React-like framework internals
- **Customizable**: Tailored specifically for project requirements
- **Performance**: Optimized for the specific use cases of the application

### Technology Stack

**Build Tools:**
- **Vite**: Fast development server with HMR
- **TypeScript**: Type-safe development with strict configuration
- **Tailwind CSS**: Utility-first CSS framework
- **ESBuild**: Fast bundling and transpilation

**Development Features:**
- **Hot Module Replacement**: Instant updates during development
- **TypeScript Strict Mode**: Enhanced type checking and safety
- **Path Aliases**: Clean import statements with @ aliases
- **Development Proxy**: API requests proxied to backend during development

### Component Architecture

**Structure:**
```
frontend/src/
├── components/          # Reusable UI components
├── pages/              # Page-level components
├── lib/                # Libraries and utilities
│   ├── minireact/      # Custom React-like framework
│   ├── store/          # State management
│   └── api/            # API communication
├── types/              # TypeScript type definitions
└── utils/              # Utility functions
```

**Component Patterns:**
- **Functional Components**: All components are functional with hooks
- **Props Interface**: Strongly typed props with TypeScript interfaces
- **Composition**: Component composition over inheritance
- **Custom Hooks**: Reusable logic extraction into custom hooks

### State Management

**Store Implementation:**
- **Custom Store**: Lightweight Redux-like state management
- **Selector Pattern**: Efficient component subscriptions
- **Batched Updates**: Optimized re-rendering with batching
- **TypeScript Integration**: Fully typed state and actions

**Features:**
- **Global State**: Application-wide state management
- **Local State**: Component-level state with useState
- **Derived State**: Computed values with memoization
- **Side Effects**: Async operations with proper cleanup

## Backend Architecture

The backend is built with **Fastify** and **Node.js**, providing a high-performance, type-safe API server.

### Technology Stack

**Core Framework:**
- **Fastify**: High-performance web framework
- **Node.js**: JavaScript runtime with TypeScript compilation
- **TypeScript**: Type-safe server-side development
- **Zod**: Runtime type validation and schema definition

**Key Libraries:**
- **@fastify/jwt**: JWT token handling
- **@fastify/cookie**: Cookie management
- **@fastify/cors**: Cross-origin resource sharing
- **@fastify/helmet**: Security headers
- **@fastify/rate-limit**: Request rate limiting
- **bcrypt**: Password hashing
- **otplib**: TOTP 2FA implementation
- **nodemailer**: Email sending
- **google-auth-library**: Google OAuth integration

### Architecture Patterns

**Modular Structure:**
```
backend/src/
├── modules/            # Feature modules
│   ├── auth/           # Authentication module
│   ├── user/           # User management module
│   ├── game/           # Game logic module
│   └── tournament/     # Tournament module
├── middleware/         # Custom middleware
├── services/           # Business logic services
├── db/                 # Database configuration and migrations
├── types/              # TypeScript type definitions
└── utils/              # Utility functions
```

**Module Pattern:**
Each module contains:
- **Controller**: Request handling and response formatting
- **Service**: Business logic and data processing
- **Routes**: API endpoint definitions
- **Schemas**: Request/response validation schemas

### API Design

**RESTful Principles:**
- **Resource-based URLs**: Clear, hierarchical URL structure
- **HTTP Methods**: Proper use of GET, POST, PUT, DELETE
- **Status Codes**: Appropriate HTTP status codes
- **Content Negotiation**: JSON request/response format

**Response Format:**
```typescript
// Success Response
{
  "message": "Operation successful",
  "data": {
    // Actual response data
  }
}

// Error Response
{
  "message": "Error description",
  "code": "ERROR_CODE"
}
```

**Security Features:**
- **Input Validation**: Zod schema validation for all endpoints
- **Rate Limiting**: Configurable rate limits per endpoint
- **CORS Configuration**: Proper cross-origin request handling
- **Security Headers**: Helmet middleware for security headers
- **Authentication Middleware**: JWT token validation
- **Authorization**: Role-based access control

## SQLite3 Database Management

The application uses **SQLite3** with **Knex.js** for database operations, providing a lightweight yet powerful data persistence layer.

### Knex.js Configuration

**Database Setup:**
```typescript
// knexfile.ts configuration
export default {
  development: {
    client: 'sqlite3',
    connection: {
      filename: process.env.DB_FILE || '../../data/database.sqlite',
    },
    migrations: {
      directory: path.resolve(currentDirPath, 'migrations'),
      extension: 'ts',
      loadExtensions: ['.js', '.ts'],
    },
    useNullAsDefault: true,
  },
  production: {
    client: 'sqlite3',
    connection: {
      filename: process.env.DB_FILE || '../../data/database.sqlite',
    },
    migrations: {
      directory: path.resolve(currentDirPath, 'migrations'),
      loadExtensions: ['.js'],
    },
    useNullAsDefault: true,
  },
};
```

### Migration System

**Migration Management:**
- **Version Control**: Database schema changes tracked in migrations
- **Rollback Support**: Ability to rollback schema changes
- **Environment Specific**: Separate migration handling for dev/prod
- **TypeScript Support**: Migrations written in TypeScript

**Key Migrations:**
1. **Initial Migration**: User accounts, basic tables
2. **Authentication**: Password reset tokens, refresh tokens
3. **Email Verification**: Email verification tokens
4. **Admin User**: Default admin account creation
5. **Games**: Matches and participants tables
6. **GDPR**: User consent tracking
7. **Tournaments**: Tournament system tables

**Migration Commands:**
```bash
# Development
npm run migrate:latest        # Apply latest migrations
npm run migrate:rollback      # Rollback last migration
npm run migrate:status        # Check migration status

# Production
npm run migrate:latest:prod   # Apply migrations in production
```

### Database Schema

**Core Tables:**
- **users**: User accounts and profiles
- **refresh_tokens**: JWT refresh token management
- **password_reset_tokens**: Password reset functionality
- **email_verification_tokens**: Email verification system
- **matches**: Game match records
- **match_participants**: Match participant data
- **tournaments**: Tournament information
- **tournament_participants**: Tournament registration
- **user_consents**: GDPR consent tracking

**Relationships:**
- Foreign key constraints for data integrity
- Cascading deletes for data cleanup
- Indexes for query performance
- Unique constraints for business rules

### Query Optimization

**Performance Features:**
- **Connection Pooling**: Efficient database connection management
- **Query Builder**: Type-safe query construction with Knex
- **Prepared Statements**: SQL injection prevention
- **Indexing Strategy**: Optimized indexes for common queries
- **Transaction Support**: ACID compliance for complex operations

## TypeScript and Vite Configuration

The project uses modern TypeScript and Vite configurations optimized for development experience and production performance.

### Backend TypeScript Configuration (`backend/tsconfig.json`)

**Key Features:**
```json
{
  "compilerOptions": {
    "target": "es2020",
    "module": "commonjs",
    "moduleResolution": "node",
    "strict": true,
    "esModuleInterop": true,
    "skipLibCheck": true,
    "forceConsistentCasingInFileNames": true,
    "resolveJsonModule": true,
    "isolatedModules": true,
    "outDir": "./dist",
    "baseUrl": ".",
    "paths": {
      "@types/*": ["./src/types/*"]
    }
  }
}
```

**Configuration Benefits:**
- **Strict Mode**: Enhanced type checking and error detection
- **Path Mapping**: Clean import statements with @ aliases
- **ES2020 Target**: Modern JavaScript features support
- **CommonJS Modules**: Node.js compatibility
- **JSON Resolution**: Import JSON files directly

### Frontend TypeScript Configuration (`frontend/tsconfig.json`)

**Key Features:**
```json
{
  "compilerOptions": {
    "target": "ES2020",
    "module": "ESNext",
    "moduleResolution": "bundler",
    "jsx": "react",
    "jsxFactory": "createElement",
    "jsxFragmentFactory": "Fragment",
    "strict": true,
    "baseUrl": ".",
    "paths": {
      "@minireact": ["./src/lib/minireact/minireact.ts"],
      "@components/*": ["./src/components/*"],
      "@pages/*": ["./src/pages/*"],
      "@utils/*": ["./src/utils/*"],
      "@lib/*": ["./src/lib/*"],
      "@types/*": ["./src/types/*"],
      "@/*": ["./src/*"]
    }
  }
}
```

**Minireact Integration:**
- **JSX Factory**: Custom createElement function for minireact
- **Fragment Factory**: Fragment component for JSX fragments
- **Path Aliases**: Convenient imports with @ prefixes
- **Bundler Resolution**: Optimized for Vite bundling

### Vite Configuration (`frontend/vite.config.ts`)

**Development Server:**
```typescript
export default defineConfig({
  server: {
    port: 5173,
    host: "0.0.0.0",
    https: {
      key: fs.readFileSync("./certs/frontend.key"),
      cert: fs.readFileSync("./certs/frontend.crt"),
    },
    hmr: {
      host: "localhost",
      protocol: "wss",
      port: 5173,
    },
    proxy: {
      "/api": {
        target: "https://backend:3000",
        changeOrigin: true,
        secure: false,
      },
    },
  },
});
```

**Build Configuration:**
```typescript
export default defineConfig({
  build: {
    outDir: "dist",
    emptyOutDir: true,
    copyPublicDir: true,
    assetsDir: "assets",
    rollupOptions: {
      output: {
        assetFileNames: "assets/[name]-[hash][extname]",
      },
    },
  },
});
```

**Key Features:**
- **HTTPS Development**: SSL certificates for secure development
- **Hot Module Replacement**: Instant updates during development
- **API Proxy**: Backend API requests proxied during development
- **Path Aliases**: Consistent with TypeScript path mapping
- **Tailwind Integration**: Tailwind CSS plugin integration
- **Asset Optimization**: Optimized asset handling for production
- **Build Optimization**: Efficient bundling with Rollup

**Development Benefits:**
- **Fast Startup**: Vite's fast cold start
- **Instant HMR**: Sub-second hot module replacement
- **TypeScript Support**: Native TypeScript compilation
- **Modern Features**: ES modules and modern JavaScript features
- **Development Tools**: Integrated development server and build tools

---

## Getting Started

### Prerequisites
- Docker and Docker Compose
- Make (for using Makefile commands)
- Node.js 18+ (for local development)

### Quick Start

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd transcendence
   ```

2. **Generate SSL certificates**
   ```bash
   make certs
   ```

3. **Start development environment**
   ```bash
   make start-dev
   ```

4. **Access the application**
   - Frontend (via Nginx): https://localhost:4433
   - Frontend (direct): https://localhost:5173
   - Backend API: https://localhost:3000 (internal)

### Development Workflow

1. **Make code changes** in `frontend/src` or `backend/src`
2. **Changes are automatically reloaded** via HMR
3. **View logs** with `make logs-dev`
4. **Access containers** with `make shell-backend-dev` or `make shell-frontend-dev`
5. **Run tests** with `make test-permissions`

### Production Deployment

1. **Build and start production environment**
   ```bash
   make start-prod
   ```

2. **Access the application**
   - Production URL: https://localhost:4443

3. **Monitor logs**
   ```bash
   make logs-prod
   ```

### Maintenance

- **Clean up resources**: `make prune`
- **Test permissions**: `make test-permissions`
- **Complete test flow**: `make test-flow`

For detailed development information, see the [minireact guide](./minireact_guide.md).
